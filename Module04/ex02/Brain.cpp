/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:01:54 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/30 14:01:55 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(){std::cout << "Brain is constructed" << std::endl;}

Brain::Brain(const Brain& src)
{
    std::cout << "Brain copy is constructed" << std::endl;
    
    for (int i = 0; i < 100; i++)
        ideas[i] = src.ideas[i];
}

Brain& Brain::operator=(const Brain& src)
{
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = src.ideas[i];
    }
    return *this;
}

Brain::~Brain(){std::cout << "Brain is destructed" << std::endl;}
