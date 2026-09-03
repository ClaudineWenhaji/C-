/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 18:16:18 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/03 18:42:11 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Colors.hpp"
#include <iostream>

int main()
{
    std::cout << std::endl;
    std::cout << GREEN << "Normal Test" << RESET << std::endl;
    std::cout << std::endl;
    
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Sortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << "Test exceptions" << RESET << std::endl;
    std::cout << std::endl;
    
    try 
    {
        sp.addNumber(42);  // Should throw - full
    } 
    catch (std::exception& e) 
    {
        std::cout << "Full: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << GREEN << "Test Empty" << RESET << std::endl;
    std::cout << std::endl;
    
    Span empty(5);
    try 
    {
        empty.shortestSpan();  // Should throw - not enough
    } 
    catch (std::exception& e) 
    {
        std::cout << "Empty: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << GREEN << "Test Largest number 10000" << RESET << std::endl;
    std::cout << std::endl;
    
    Span big(10000);
    std::vector<int> manyNumbers;
    for (int i = 0; i < 10000; i++) {
        manyNumbers.push_back(i);
    }
    big.addNumber(manyNumbers.begin(), manyNumbers.end());

    std::cout << "Big shortest: " << big.shortestSpan() << std::endl;  // 1
    std::cout << "Big longest: " << big.longestSpan() << std::endl;  // 9999
    std::cout << std::endl;
    
    return 0;
}