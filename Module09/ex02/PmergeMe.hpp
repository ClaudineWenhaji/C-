/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 12:19:52 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/14 11:34:10 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstddef>

class PMergeMe
{
    private:
       
        struct Pair
        {
            int small;
            int large;
        };
    
        std::vector<int> _vec;
        std::deque<int> _deq;
        double _vecTime;
        double _deqTime;

        size_t jacobsthal(int n);

    public:
    
        PMergeMe();
        PMergeMe(const PMergeMe& copy);
        PMergeMe& operator=(const PMergeMe& src);
        ~PMergeMe();
        
        void ParseInput(int ac, char** av);
        void sort();
        void displayBefore() const;
        void displayAfter() const;
        void displayTime() const;

        void sortVector();
        void sortDeque();
};

#endif