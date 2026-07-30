/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:00:21 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/30 14:00:22 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal{
    public:

        Dog();
        Dog(const Dog &src);
        Dog& operator=(const Dog& src);
        ~Dog();

        void makeSound()const {std::cout << "Woof! Woof!" << std::endl;};
};

#endif