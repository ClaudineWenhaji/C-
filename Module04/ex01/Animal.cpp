/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:00:54 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/30 14:00:55 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Generic Animal")
{
    std::cout << "Animal is constructed" << std::endl;
}

Animal::Animal(const Animal& src): type(src.type)
{
    std::cout << "Animal copy is constructed" << std::endl;
}

Animal& Animal::operator=(const Animal& src)
{
    //std::cout << "Animal assigment operator" << std::endl;

    if (this != &src)
        type = src.type;
    return *this;
}

Animal::~Animal() {std::cout << "Animal is destructed" << std::endl;}

std::string Animal::getType() const {return type;}