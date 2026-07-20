/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:47:46 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/20 17:46:32 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// With virtual inheritance, the MOST DERIVED class
// must inizialize the virtual base
DiamondTrap::DiamondTrap(std::string Name):
    ClapTrap(Name + "_clap_name"),    // DiamondTrap initializes ClapTrap
    ScavTrap(Name),                   // ScavTrap's ClapTrap init is ignored
    FragTrap(Name),                   // FragTrap's ClapTrap init is ignored
    Name(Name)
{
    // Attributes from FragTrap except energy from ScavTrap
    hitPoints    = FragTrap::hitPoints;         // or 100
    energyPoints = ScavTrap::energyPoints;      // or 50
    attackDamage = FragTrap::attackDamage;      // or 30
    
    std::cout << "DiamondTrap " << Name << " Constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src):
    ClapTrap(src),
    ScavTrap(src),
    FragTrap(src),
    Name(src.Name)
{
    std::cout << "DiamondTrap " << Name 
              << " DiamondTrap Copy constructed!" 
              << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
    if (this != &src)
    {
        ClapTrap::operator=(src);
        Name = src.Name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap(){std::cout << "DiamondTrap " << Name << " Destructed!" << std::endl;}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << Name << std::endl;
    std::cout << "My ClapTrap name is " << ClapTrap::Name << std::endl;
}