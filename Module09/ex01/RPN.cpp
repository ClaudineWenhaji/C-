/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:12:18 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/08 11:15:25 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>

RPN::RPN() {}
RPN::RPN(const RPN& copy) : _stack(copy._stack) {}
RPN& RPN::operator=(const RPN& src)
{
    if (this != &src)
        _stack = src._stack;
    return *this;
}
RPN::~RPN() {}

// ----------------------- REVERSE POLISH NOTATION PROGRAM -----------------------------//

int RPN::evaluate(const std::string& expression)
{
    while(!_stack.empty())
        _stack.pop();

    for (size_t i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        
        if (c == ' ')
            continue;
            
        if (std::isdigit(c))
            _stack.push(c - '0'); // doit pusher un digit (0 - 9) donc c - 48
            
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");
            
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();

            int result;
            switch (c)
            {
                case '+':
                    result = a + b; break;
                case '-':
                    result = a - b; break;
                case '*':
                    result = a * b; break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("Error");
                    result = a / b; break;
                default:
                    throw std::runtime_error("Error");   
            }
            _stack.push(result); // result is now at top of the stack
        }
        else
            throw std::runtime_error("Error");
    }
    
    if (_stack.size() != 1) // should contains only the result at the end 
        throw std::runtime_error("Error");
        
    return _stack.top();
}