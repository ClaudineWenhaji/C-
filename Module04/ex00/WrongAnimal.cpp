/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:00:34 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/30 14:00:35 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Generic Wrong Animal")
{
    std::cout << "WrongAnimal is constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src): type(src.type)
{
    std::cout << "WrongAnimal copy is constructed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
    //std::cout << "WrongAnimal assigment operator" << std::endl;

    if (this != &src)
        type = src.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal is destructed" << std::endl;}

std::string WrongAnimal::getType() const {return type;}