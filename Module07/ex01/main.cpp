/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:37:28 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/01 11:34:59 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "Colors.hpp"

template <typename T>
void print(T const& elem) {
    std::cout << elem << " ";
}

template <typename T>
void increment(T& elem) {
    elem += 2;
}

int main() 
{
    // Test with int array
    std::cout << std::endl;
    std::cout << GREEN << " Test with int array " << RESET << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "Int array: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;
    
    // Test with increment
    std::cout << std::endl;
    std::cout << GREEN << " Test with increment int array " << RESET << std::endl;
    iter(numbers, 5, increment<int>); 
    std::cout << "Values doubled: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    // Test with float array
    std::cout << std::endl;
    std::cout << GREEN << " Test with float array " << RESET << std::endl;
    float numbers1[] = {1.0f, 2.1f, -3.2f, 4.0f, -5.0f};
    std::cout << "Float array: ";
    iter(numbers1, 5, print<float>);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << " Test with string array " << RESET << std::endl;
    std::string words[] = {"hello", "world", "test"};
    std::cout << "String array: ";
    iter(words, 3, print<std::string>);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << GREEN << " Test with empty array " << RESET << std::endl;
    int empty[1] = {0};
    iter(empty, 0, print<int>);  // Should do nothing
    std::cout << "Empty array passed" << std::endl;
    std::cout << std::endl;

    return 0;
}