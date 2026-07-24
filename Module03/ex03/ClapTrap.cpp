/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:29:31 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/24 17:36:44 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " Default Constructed!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " Constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
    : name(src.name),
      hitPoints(src.hitPoints),
      energyPoints(src.energyPoints),
      attackDamage(src.attackDamage)
{
    std::cout << "ClapTrap " << name << " Copy constructed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
    std::cout << "ClapTrap " << name << " Assignment operator" << std::endl;
    
    if (this != &src)
    {
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << name << " Destructed!" << std::endl;
}

// Setters
void ClapTrap::setName(std::string name)
{
    this->name = name;
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
std::string ClapTrap::getName() {return name;}
unsigned int ClapTrap::getEnergyPoints() {return energyPoints;}
unsigned int ClapTrap::getHitPoints() {return hitPoints;}
unsigned int ClapTrap::getAttackDamage() {return attackDamage;}

// Member Functions

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "ClapTrap " << name 
                  << " Can't do anything. No hit/energy points. " 
                  << std::endl;
        return ;
    }
    energyPoints -= 1;
    
    std::cout << "ClapTrap " << name 
              << " attacks " << target 
              << " causing " << attackDamage 
              << " points of damage! Energy Points: "
              << energyPoints << std::endl;
    return ;

}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already dead!"
                  << std::endl;
        return ;
    }
    if (amount >= hitPoints)
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount 
                  << " points of damage. HP: " << hitPoints
                  << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount
                  << " points of damage! Remaining hitpoints: "
                  << hitPoints << std::endl;
    }
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " Can't be repaired. No hit/energy points. "
                  << std::endl;
        return ;
    }
    energyPoints -= 1;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired by " << amount 
              << " points. HP: " << hitPoints 
              << " Energy Points: " << energyPoints
              << std::endl;
    return ;
}