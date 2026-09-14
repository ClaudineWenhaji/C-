/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:35:05 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/14 15:47:53 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PMergeMe::PMergeMe() {}
PMergeMe::PMergeMe(const PMergeMe& copy) { *this = copy;}
PMergeMe& PMergeMe::operator=(const PMergeMe& src)
{
    if (this != &src)
    {
        _vec = src._vec;
        _deq = src._deq;
        _vecTime = src._vecTime;
        _deqTime = src._deqTime;
    }
    return *this;
}
PMergeMe::~PMergeMe() {}

// ----------------------------- PARSING ------------------------------ //

void PMergeMe::ParseInput(int ac, char** av)
{
    if (ac < 2)
        throw std::runtime_error("Error");
        
    for (int i = 1; i < ac; i++)
    {
        std::string token = av[i];
        
        if (token.empty())
            throw std::runtime_error("Error: empty argument");
            
        for (size_t j = 0; j < token.size(); j++)
        {
            if (!std::isdigit(static_cast<unsigned char>(token[j])))
                throw std::runtime_error("Error: not a digit");
        }
        
        char* end = NULL;
        long value = std::strtol(token.c_str(), &end, 10);

        if (*end != '\0' )
            throw std::runtime_error("Error");
        if (value < 0)
            throw std::runtime_error("Error: Negative number");
        if (value > 2147483647)
            throw std::runtime_error("Error: Integer overflow");
            
        _vec.push_back(static_cast<int>(value));
        _deq.push_back(static_cast<int>(value));
    }
}

// ****************************************************************************** //
//                 FORD-JOHNSON ALGORITHM: Merge-Insertion SORT                   //
// ****************************************************************************** //

size_t PMergeMe::jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
        
    size_t previous = 0;
    size_t current = 1;
    
    for (int i = 2; i <= n; ++i)
    {
        size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return current; 
    
    //     J(n) = J(n-1) + 2*J(n-2) with J(0) = 0 et J(1) = 1
    //     0, 1, 1, 3, 5, 11, 21, 43, 85, 171, ...
    //     les nombres qui interessent dans Ford-Johnson sont
    //     1, 3, 4, 11, 21, 43, 85 ...
}

// -------------------- WITH STD::VECTOR -----------------------//

void PMergeMe::sortVector()
{
    if (_vec.size() < 2)
        return; 
         
    // ---------- nombre d'elements pair ou impair ---------- //
    
    bool hasOdd = (_vec.size() % 2 != 0);
    
    int oddElt = 0;
    size_t limit = _vec.size();
    
    if (hasOdd)
    {
        oddElt = _vec.back();
        --limit;
    }
        
    // --------- Former des Paires: petit a gauche - grand a droite ----------- //

    std::vector<Pair> pairs;
    
    for (size_t i = 0; i < limit; i += 2)
    {
        Pair p;
        
        if (_vec[i] < _vec[i + 1])
        {
            p.small = _vec[i];
            p.large = _vec[i + 1];
        }
        else
        {
            p.small = _vec[i + 1];
            p.large = _vec[i];
        }
        pairs.push_back(p);
    }

    // ----------- Tri recursif des grands ------------ //
    
    std::vector<int> larger;

    for (size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].large);
        
    _vec = larger;
    sortVector();
    larger = _vec;

    // ------------ Reconstituer les paires small -> large --------------- //

    std::vector<Pair> sortedPairs;
    std::vector<bool> used(pairs.size(), false);
    
    for (size_t i = 0; i < larger.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].large == larger[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    // ---------------- Main Chain ------------------ //
    
    std::vector<int> mainChain;
    
    for (size_t i = 0; i < sortedPairs.size(); ++i)
        mainChain.push_back(sortedPairs[i].large); // contient les les grands elts tries recursivement

    
        // ------------------ Inserer les petits elts dans mainChain ------------------ //
    
    // D'abord le 1er elt de smaller (car correspond au 1er elt de larger) 

    if (!sortedPairs.empty())
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), sortedPairs[0].small);
        mainChain.insert(pos, sortedPairs[0].small);
    }
    
    // --- Ensuite, Utiliser la suite de Jacobsthal 
    // --- pour optimiser l'ordre d'insertion des petits par une recherche binaire
    // --- Ford-Johnson choisit les indices 1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, 20, ...
    // --- et les frontieres sont Jacobsthal: 1, 3, 5, 11, 21, 43, ...
    // --- Entre 2 frontieres, on parcourt les indices a l'envers
    
    size_t previous = 1;
    
    for (int k = 3; ; ++k)
    {
        size_t current = jacobsthal(k);
        
        if (current > sortedPairs.size())
            current = sortedPairs.size();
        
        // on genere les indices a inserer a l'envers dans le groupe
        for (size_t i = current; i > previous; --i)
        {
            size_t index = i - 1;
            
            int value = sortedPairs[index].small;
            int bound = sortedPairs[index].large; 
            
            // Ensuite on ne cherche le small que jusqu'a son propre large
            // pour limiter la recherche binaire
            
            std::vector<int>::iterator end = std::lower_bound(mainChain.begin(), mainChain.end(), bound);
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), end, value);
            mainChain.insert(pos, value);
        }
        previous = current;
        if (current == sortedPairs.size())
            break;
    }

    // --- puis on insere l'element impair s'il existe
    
    if (hasOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElt);
        mainChain.insert(pos, oddElt);
    }
    
    _vec = mainChain;
}


// ------------------------------ WITH STD::DEQUE: Pas de memoire contigue mais aux 2 extremites ------------------------------//
// ----- Moins adapte qu'un Vector pour profiter au max de la memoire contigue -------


void PMergeMe::sortDeque()
{
    if (_deq.size() < 2)
        return;
    
    // ---------- nombre d'elements pair ou impair ---------- //
    
    bool hasOdd = (_deq.size() % 2 != 0);
    
    int oddElt = 0;
    size_t limit = _deq.size();
    
    if (hasOdd)
    {
        oddElt = _deq.back();
        --limit;
    }
        
    // --------- Former des Paires: petit a gauche - grand a droite ----------- //

    std::vector<Pair> pairs;
    
    for (size_t i = 0; i < limit; i += 2)
    {
        Pair p;
        
        if (_deq[i] < _deq[i + 1])
        {
            p.small = _deq[i];
            p.large = _deq[i + 1];
        }
        else
        {
            p.small = _deq[i + 1];
            p.large = _deq[i];
        }
        pairs.push_back(p);
    }

    // ----------- Tri recursif des grands ------------ //
    
    std::deque<int> larger;

    for (size_t i = 0; i < pairs.size(); ++i)
        larger.push_back(pairs[i].large);
        
    _deq = larger;
    sortDeque();
    larger = _deq;

    // ------------ Reconstituer les paires small -> large --------------- //

    std::deque<Pair> sortedPairs;
    std::deque<bool> used(pairs.size(), false);
    
    for (size_t i = 0; i < larger.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].large == larger[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    // ---------------- Main Chain ------------------ //
    
    std::deque<int> mainChain;
    
    for (size_t i = 0; i < sortedPairs.size(); ++i)
        mainChain.push_back(sortedPairs[i].large); // contient les les grands elts tries recursivement

    // ------------------ Inserer les petits ------------------ //
     
    // D'abord le 1er elt de smaller (car correspond au 1er elt de larger) 

    if (!sortedPairs.empty())
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), sortedPairs[0].small);
        mainChain.insert(pos, sortedPairs[0].small);
    }
    
    // --- Ensuite, Utiliser la suite de Jacobsthal 
    // --- pour optimiser l'ordre d'insertion des petits par une recherche binaire
    // --- Ford-Johnson choit les indices 1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, 20, ...
    // --- et les frontieres sont Jacobsthal: 1, 3, 5, 11, 21, 43, ...
    // --- Entre 2 frontieres, on parcourt les indices a l'envers
    
    size_t previous = 1;
    
    for (int k = 3; ; ++k)
    {
        size_t current = jacobsthal(k);
        
        if (current > sortedPairs.size())
            current = sortedPairs.size();
        
        // on genere les indices a inserer a l'envers dans le groupe
        for (size_t i = current; i > previous; --i)
        {
            size_t index = i - 1;
            
            int value = sortedPairs[index].small;
            int bound = sortedPairs[index].large; 
            
            // Ensuite on ne cherche le small que jusqu'a son propre large
            // pour limiter la recherche binaire
            
            std::deque<int>::iterator end = std::lower_bound(mainChain.begin(), mainChain.end(), bound);
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), end, value);
            mainChain.insert(pos, value);
        }
        previous = current;
        
        if (current == sortedPairs.size())
            break;
    }

    // --- puis on insere l'element impair s'il existe
    
    if (hasOdd)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElt);
        mainChain.insert(pos, oddElt);
    }
    
    _deq = mainChain;
}

// -------------------------- SORTING -------------------------- //

void PMergeMe::sort()
{
    clock_t startVec = clock();
    sortVector();
    clock_t endVec = clock();
    _vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    
    clock_t startDeq = clock();
    sortDeque();
    clock_t endDeq = clock();
    _deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
}

// --------------------------DISPLAY TIME ----------------------------- //

void PMergeMe::displayTime() const
{
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector: " 
              << _vecTime << " microseconds" << std::endl;
              
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque: " 
              << _deqTime << " microseconds" << std::endl;
}

// -------------------------- DISPLAY FORMAT --------------------------- //

void PMergeMe::displayBefore() const
{
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator i = _vec.begin(); i != _vec.end(); ++i)
    {
        if (i != _vec.begin())
            std::cout << " ";
        std::cout << *i;
    }
    std::cout << std::endl;
}

void PMergeMe::displayAfter() const
{
    std::cout << "After: ";
    for (std::vector<int>::const_iterator i = _vec.begin(); i != _vec.end(); ++i)
    {
        if (i != _vec.begin())
            std::cout << " ";
        std::cout << *i;
    }
    std::cout << std::endl;
}
