/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:00:17 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/30 14:00:18 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
    this->type = "Dog";
    std::cout << "Dog is constructed" << std::endl;
}

Dog::Dog(const Dog& src): Animal(src)
{
    this->type = src.type;
    std::cout << " Dog copy is constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
    if (this != &src)
        type = src.type;
    return *this;
}

Dog::~Dog(){std::cout << "Dog is destructed" << std::endl;}
