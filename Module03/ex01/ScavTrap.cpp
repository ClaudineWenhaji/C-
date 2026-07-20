/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:32:08 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/20 15:56:55 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(" Default")
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << Name << " ScavTrap Default Constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << Name << " ScavTrap Constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src)
{
    std::cout << "ScavTrap " << Name << " ScavTrap Copy constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
    std::cout << "ScavTrap " << Name << " ScavTrap Assignment operator" << std::endl;
    
    if (this != &src)
        ClapTrap::operator=(src);
    return *this;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap " << getName() << " ScavTrap Destructor" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap" << getName() << " is now in Gatekeeper mode."
              << std::endl;
}

void ScavTrap::attack(const std::string& target) 
{
    if (!hitPoints || !energyPoints)
    {
        std::cout << "ScavTrap " << Name << " Can't do anything. No hit/energy points. " << std::endl;
        return ;
    }
    energyPoints -= 1;
    std::cout << "ScavTrap " << Name << " attacks " << target 
              << " causing " << attackDamage << " points of damage!"
              << std::endl;
    return ;
}