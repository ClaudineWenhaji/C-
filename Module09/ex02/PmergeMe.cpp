/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:35:05 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/10 13:06:36 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <iostream>

PMergeMe::PMergeMe() {}
PMergeMe::PMergeMe(const PMergeMe& copy) { *this = copy;}
PMergeMe& PMergeMe::operator=(const PMergeMe& src)
{
    if (this != &src)
    {
        _vec = src._vec;
        _deq = src._deq;
    }
    return *this;
}
PMergeMe::~PMergeMe() {}

void PMergeMe::sortVector()
{
    if (_vec.size() < 2)
        return; 
         
    // ---------- nombre d'elements pair ou impair ---------- //
    
    bool hasOdd = (_vec.size() % 2 != 0);
    int oddElt = hasOdd ? _vec.back() : 0;
        
    // --------- Former des Paires: petit a gauche - grand a droite ----------- //
    
    std::vector<int> larger;
    std::vector<int> smaller;

    size_t limit = hasOdd ? _vec.size() - 1 : _vec.size();
    
    for (size_t i = 0; i < limit; i += 2)
    {
        if (_vec[i] > _vec[i + 1])
        {
            larger.push_back(_vec[i]);
            smaller.push_back(_vec[i + 1]);
        }
        else
        {
            larger.push_back(_vec[i + 1]);
            smaller.push_back(_vec[i]);
        }
    }

    // ----------- Trier recursivement les grands ------------ //
    
    _vec = larger;
    sortVector();
    larger = _vec;
    
    // ------------------ Inserer les petits ------------------ //
    // D'abord le 1er elt de smaller (car correspond au 1er elt de larger) 

    if (!smaller.empty())
    {
        std::vector<int>::iterator pos = std::lower_bound(larger.begin(), larger.end(), smaller[0]);
        larger.insert(pos, smaller[0]);
    }
    
    // --- Ensuite, la suite de Jacobsthal optimise les insertions
    // --- par une recherche binaire
    
    for (size_t i = 1; i < smaller.size(); i++)
    {
        std::vector<int>::iterator pos = std::lower_bound(larger.begin(), larger.end(), smaller[i]);
        larger.insert(pos, smaller[i]);
    }

    // --- puis on insere l'element impair s'il existe
    
    if (hasOdd)
    {
        std::vector<int>::iterator pos = std::lower_bound(larger.begin(), larger.end(), oddElt);
        larger.insert(pos, oddElt);
    }
    
    _vec = larger;
}

void PMergeMe::ParseInput(int ac, char** av)
{
    for (int i = 1; i < ac; i++)
    {
        int num = std::atoi(av[i]);
        
        if (num < 0)
            throw std::runtime_error("Error: negative number");
        if (num > 2147483647)
            throw std::runtime_error("Error: Interger overflow");
            
        _vec.push_back(static_cast<int>(num));
        _deq.push_back(static_cast<int>(num));
    }
}

void PMergeMe::sort()
{
    clock_t startVec = clock();
    sortVector();
    clock_t endVec = clock();
    double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000.0;
    
    //clock_t startDeq = clock();
    //sortDeque();
    //clock_t endDeq = clock();
    //double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000.0;
    
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector: " << vecTime << " us" << std::endl;
              
    //std::cout << "Time to process a range of " << _deq.size()
    //        << " elements with std::deque: " << deqTime << " us" << std::endl;
}

void PMergeMe::displayBefore() const
{
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator i = _vec.begin(); i != _vec.end(); ++i)
    {
        std::cout << *i;
        if (i + 1 != _vec.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PMergeMe::displayAfter() const
{
    std::cout << "After: ";
    for (std::vector<int>::const_iterator i = _vec.begin(); i != _vec.end(); ++i)
    {
        std::cout << *i;
        if (i + 1 != _vec.end())
            std::cout << " ";
    }
    std::cout << std::endl;
}