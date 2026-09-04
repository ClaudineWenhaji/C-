/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 17:17:01 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/04 11:23:19 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): _N(n) {}
Span::Span(const Span& copy):  _N(copy._N), _numbers(copy._numbers) {}
Span& Span::operator=(Span const& src)
{
    if (this != &src)
    {
        _N = src._N;
        _numbers = src._numbers;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _N)
        throw std::runtime_error("Span is full");
    _numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Can not span: Too few numbers");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    int minimumSpan = sorted[1] - sorted[0];
    
    for (size_t i = 2; i < sorted.size(); i++)
    {
        int span = sorted[i] - sorted[i - 1];
        
        if (span < minimumSpan)
            minimumSpan = span;
    }
    return minimumSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Can not span: Too few numbers");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}