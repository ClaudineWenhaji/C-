/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:47:29 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/27 16:36:20 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Colors.hpp"
#include <iostream>

int main()
{
    Data test = {2, 'H' , 3.14f, 42};
    
    std::cout << std::endl;
    std::cout << GREEN << "Before serialise()" << RESET << std::endl
              << "Address: " << &test << std::endl
              << "Int: " << test.int_value << std::endl
              << "Char: " << test.char_value << std::endl
              << "Float: " << test.float_value << std::endl
              << "Double: " << test.double_value << std::endl;
    
    uintptr_t converted = Serializer::serialize(&test);
    std::cout << std::endl;
    
    std::cout << GREEN << "After serialise()" << RESET << std::endl
              << "Original address: " << &test << std::endl
              << "Serialized value: " << converted << std::endl;
              
    Data *reconverted = Serializer::deserialize(converted);
    std::cout << std::endl;
    
    std::cout << GREEN << "After deserialise()" << RESET << std::endl
              << "Address: " << reconverted << std::endl
              << "Int: " << reconverted->int_value << std::endl
              << "Char: " << reconverted->char_value << std::endl
              << "Float: " << reconverted->float_value << std::endl
              << "Double: " << reconverted->double_value << std::endl;
}