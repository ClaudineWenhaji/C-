/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:01:23 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/30 14:01:24 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{

    private:
        Brain* dogBrain; // dynamic allocation

    public:

        Dog();
        Dog(const Dog &src);
        Dog& operator=(const Dog& src);
        ~Dog();

        void makeSound()const {std::cout << "Woof! Woof!" << std::endl;};
        Brain* getBrain() const;
};

#endif