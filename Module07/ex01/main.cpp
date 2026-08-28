/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:37:28 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/28 17:35:02 by clwenhaj         ###   ########.fr       */
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
    elem *= 2;
}

int main() 
{
    // Test with int array
    int numbers[] = {1, 2, 3, 4, 5};
    
    std::cout << "Int array: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    iter(numbers, 5, doubleValue<int>);
    
    std::cout << "Doubled: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    // Test with string array
    std::string words[] = {"hello", "world", "test"};
    std::cout << "String array: ";
    iter(words, 3, print<std::string>);
    std::cout << std::endl;

    // Test with empty array
    int empty[1] = {0};
    iter(empty, 0, print<int>);  // Should do nothing
    std::cout << "Empty test passed" << std::endl;


    return 0;
}