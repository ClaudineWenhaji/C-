/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 12:19:52 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/10 15:34:31 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>

class PMergeMe
{
    private:
    
        std::vector<int> _vec;
        std::deque<int> _deq;
      
        void sortVector();
        void sortDeque();

    public:
    
        PMergeMe();
        PMergeMe(const PMergeMe& copy);
        PMergeMe& operator=(const PMergeMe& src);
        ~PMergeMe();

        void ParseInput(int ac, char** av);
        void sort();
        void displayBefore() const;
        void displayAfter() const;
};

#endif