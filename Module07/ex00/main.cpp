/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:37:28 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/28 17:28:35 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"
#include "Colors.hpp"

int main() 
{
    std::cout << std::endl;
    std::cout << BLUE <<  "------- Test1:  with int -------" << RESET << std::endl;
    std::cout << std::endl;

    int a = 2, b = 3;
    
    std::cout << GREEN << "Before swap: a = " << a << ", b = " << b << RESET << std::endl;
    
    ::swap(a, b);
    
    std::cout << GREEN << "After swap:  a = " << a << ", b = " << b << RESET << std::endl;
    std::cout << "min(a, b): " << ::min(a, b) << std::endl;
    std::cout << "max(a, b): " << ::max(a, b) << std::endl;

    std::cout << std::endl;
    std::cout << BLUE <<  "------- Test2:  with string -------" << RESET << std::endl;
    std::cout << std::endl;
    
    std::string c = "chaine1", d = "chaine2";
    
    ::swap(c, d);
    
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d): " << ::min(c, d) << std::endl;
    std::cout << "max(c, d): " << ::max(c, d) << std::endl;

    std::cout << std::endl;
    
    // Test equal case - should return second
    std::cout << BLUE <<  "------- Test3:  with equal case -------" << RESET << std::endl;
    std::cout << std::endl;
    
    int x = 5, y = 5;
    
    std::cout << "Equal test: &x = " << &x << ", &y = " << &y << std::endl;
    std::cout << "min returns: " << &(::min(x, y)) << std::endl;
    std::cout << "max returns: " << &(::max(x, y)) << std::endl;
    // Should print &y for both!
    std::cout << std::endl;

    return 0;
}