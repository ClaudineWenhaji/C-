/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:01:19 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/30 14:01:20 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
    this->type = "Dog";
    // each dog has its own Brain
    this->dogBrain = new Brain(); // Brain allocation
    std::cout << "Dog is constructed" << std::endl;
}

// Deep copy: This will create new Brain with same content
Dog::Dog(const Dog& src): Animal(src)
{
    std::cout << "Dog DEEP copy is constructed" << std::endl;

    this->dogBrain = new Brain(*src.dogBrain);  // copy the content of brain
}

// Deep copy assignment
Dog& Dog::operator=(const Dog& src)
{
    if (this != &src)
    {
        delete dogBrain;            // free old brain
        dogBrain = new Brain(*src.dogBrain); // copy new brain
    }
    return *this;
}

Dog::~Dog()
{
    delete dogBrain; // free Brain
    std::cout << "Dog is destructed" << std::endl;
}

Brain* Dog::getBrain() const{return dogBrain;}