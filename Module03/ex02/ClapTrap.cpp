/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:29:31 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/20 17:39:09 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << Name << " ClapTrap Default Constructed!" << std::endl;
}

ClapTrap::ClapTrap(std::string Name): Name(Name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << Name << " ClapTrap Constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "ClapTrap " << Name << " ClapTrap Copy constructed!" << std::endl;
    *this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
    std::cout << "ClapTrap " << Name << " ClapTrap Assignment operator" << std::endl;
    
    if (this != &src)
    {
        this->Name = src.Name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << Name << " ClapTrap Destructed!" << std::endl;
}

// Setters
void ClapTrap::setName(std::string Name)
{
    this->Name = Name;
    return ;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
    this->hitPoints = hitPoints;
    return ;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
    this->energyPoints = energyPoints;
    return ;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    this->attackDamage = attackDamage;
    return ;
}

// Getters
std::string ClapTrap::getName() {return Name;}
unsigned int ClapTrap::getEnergyPoints() {return energyPoints;}
unsigned int ClapTrap::getHitPoints() {return hitPoints;}
unsigned int ClapTrap::getAttackDamage() {return attackDamage;}

// Member Functions

void ClapTrap::attack(const std::string& target)
{
    if (!hitPoints || !energyPoints)
    {
        std::cout << "ClapTrap " << Name << " Can't do anything. No hit/energy points. " << std::endl;
        return ;
    }
    energyPoints -= 1;
    std::cout << "ClapTrap " << Name << " attacks " << target 
              << " causing " << attackDamage << " points of damage!"
              << std::endl;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!hitPoints)
    {
        std::cout << "ClapTrap " << Name << " is already dead!"
                  << std::endl;
        return ;
    }
    if (amount >= hitPoints)
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << Name << " takes" << amount 
                  << " points of damage. HP: " << hitPoints
                  << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount
                  << " points of damage! Remaining hitpoints: "
                  << hitPoints << std::endl;
    }
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!hitPoints || !energyPoints)
    {
        std::cout << "ClapTrap " << Name << " Can't be repaired. No hit/energy points. "
                  << std::endl;
        return ;
    }
    energyPoints -= 1;
    hitPoints += amount;
    std::cout << "ClapTrap " << Name << " is repaired by " << amount 
              << " points. HP: " << hitPoints
              << std::endl;
    return ;
}