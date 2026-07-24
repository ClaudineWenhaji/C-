/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:47:46 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/24 17:20:30 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// With virtual inheritance, the MOST DERIVED class
// must inizialize the virtual base
DiamondTrap::DiamondTrap(const std::string& name):
    ClapTrap(name + "_clap_name"),    // DiamondTrap initializes ClapTrap
    ScavTrap(name),                   // ScavTrap's ClapTrap init is ignored
    FragTrap(name),                   // FragTrap's ClapTrap init is ignored
    name(name)
{
    // Attributes from FragTrap except energy from ScavTrap
    hitPoints    = FragTrap::hitPoints;         // or 100
    energyPoints = ScavTrap::energyPoints;      // or 50
    attackDamage = FragTrap::attackDamage;      // or 30
    
    std::cout << "DiamondTrap " << name << " Constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src):
    ClapTrap(src),
    ScavTrap(src),
    FragTrap(src),
    name(src.name)
{
    std::cout << "DiamondTrap " << name 
              << " Copy constructed!" 
              << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
    if (this != &src)
    {
        ClapTrap::operator=(src);
        name = src.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap(){std::cout << "DiamondTrap " << name << " Destructed!" << std::endl;}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << std::endl;
    std::cout << "My ClapTrap name is " << ClapTrap::name << std::endl;
}
