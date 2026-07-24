/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:32:08 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/24 16:22:20 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(" Default")
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " Default Constructed" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " Constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src)
{
    std::cout << "ScavTrap " << name << " Copy constructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
    std::cout << "ScavTrap " << name << " Assignment operator" << std::endl;
    
    if (this != &src)
        ClapTrap::operator=(src);
    return *this;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap " << getName() << " Destructed" << std::endl;
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
        std::cout << "ScavTrap " << name << " Can't do anything. No hit/energy points. " << std::endl;
        return ;
    }
    energyPoints -= 1;
    std::cout << "ScavTrap " << name << " attacks " << target 
              << " causing " << attackDamage << " points of damage!"
              << std::endl;
    return ;
}