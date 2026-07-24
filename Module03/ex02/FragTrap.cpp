/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:12:36 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/24 13:02:09 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Default")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap" << name 
              << " Default constructed!" 
              << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
    
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name 
              << " Constructed!" 
              << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
    std::cout << "FragTrap " << name << " Copy constructed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
    std::cout << "FragTrap " << name << " Assignment operator" << std::endl;
    
    if (this != &src)
        FragTrap::operator=(src);
    return *this;
}

FragTrap::~FragTrap(){std::cout << "FragTrap " << getName() << " Destructed!" << std::endl;}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << getName() << " high-fives request."
              << std::endl;
}