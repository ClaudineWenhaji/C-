/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 12:19:52 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/11 12:05:53 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
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

        void sortVector();
        void sortDeque();
};

#endif