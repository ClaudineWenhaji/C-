/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:35:05 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/14 17:17:20 by clwenhaj         ###   ########.fr       */
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
//                                SUITE DE JACOBSTAL                              //
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

// -------------------------- SORTING -------------------------- //

void PMergeMe::sort()
{
    clock_t startVec = clock();
    sortContainer(_vec);
    clock_t endVec = clock();
    _vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    
    clock_t startDeq = clock();
    sortContainer(_deq);
    clock_t endDeq = clock();
    _deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
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
