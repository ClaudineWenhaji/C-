/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:47:29 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/26 18:01:43 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data test = {2, "Boss", 42};
    
    std::cout << "Before serialise()" << std::endl
              << "Id: " << test.id << std::endl
              << "Name: " << test.name << std::endl
              << "Value: " << test.value << std::endl;
    
    uintptr_t converted = Serializer::serialize(&test);
    std::cout << std::endl;
    std::cout << "After serialise()" << std::endl
              << "Id: " << *reinterpret_cast<int *>(converted) << std::endl
              << "Name: " << *reinterpret_cast<char *>(converted) << std::endl
              << "Value: " << *reinterpret_cast<int *>(converted)
              << std::endl;

    Data *reconverted = Serializer::deserialize(converted);
    std::cout << std::endl;
    std::cout << "After deserialise()" << std::endl
              << "Id: " << reconverted->id << std::endl
              << "Name: " << reconverted->name << std::endl
              << "Value: " << reconverted->value
              << std::endl;
}