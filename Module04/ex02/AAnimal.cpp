/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:01:47 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/30 14:01:48 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): type("Generic Animal")
{
    std::cout << "Animal is constructed" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src): type(src.type)
{
    std::cout << "Animal copy is constructed" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& src)
{
    //std::cout << "Animal assigment operator" << std::endl;

    if (this != &src)
        type = src.type;
    return *this;
}

AAnimal::~AAnimal() {std::cout << "Animal is destructed" << std::endl;}

void AAnimal::makeSound() const {std::cout << "Some generic sound" << std::endl;}

std::string AAnimal::getType() const {return type;}