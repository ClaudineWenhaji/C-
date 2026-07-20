/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:12:36 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/20 17:45:41 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Default")
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap" << Name 
              << " FragTrap Default constructed!" 
              << std::endl;
}

FragTrap::FragTrap(std::string Name): ClapTrap(Name)
{
    
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << Name 
              << " FragTrap Constructed!" 
              << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
    std::cout << "FragTrap " << Name << " FragTrap Copy constructed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
    std::cout << "FragTrap " << Name << " FragTrap Assignment operator" << std::endl;
    
    if (this != &src)
        FragTrap::operator=(src);
    return *this;
}

FragTrap::~FragTrap(){std::cout << "FragTrap " << getName() << " FragTrap Destructed!" << std::endl;}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << getName() << " high-fives request."
              << std::endl;
}