/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:06:16 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/04 15:58:43 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _numbers;

    public:
        Span(unsigned int n);
        Span(const Span& copy);
        Span& operator=(Span const& src);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        // For range addition: to add many numbers from a range of numbers
        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end)
        {
            while(begin != end)
            {
                addNumber(*begin); // deference, needs the value not the pointor
                ++begin;
            }
        }
};

#endif