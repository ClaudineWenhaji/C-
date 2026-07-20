#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
    Name("default"),
    hitPoints(10),
    energyPoints(10),
    attackDamage(0)
{
    std::cout << "Default constructor" << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string Name):

    Name(Name),
    hitPoints(10),
    energyPoints(10),
    attackDamage(0)
{
    std::cout << "ClapTrap " << Name << " constructed!" << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    *this = src;
    std::cout << "ClapTrap " << Name << " Constructed" << std::endl;
    return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
    std::cout << "ClapTrap " << Name << " Operator overloads" << std::endl;
    
    if (this == &src)
        return *this;
    this->Name = src.Name;
    this->hitPoints = src.hitPoints;
    this->energyPoints = src.energyPoints;
    this->attackDamage = src.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap() {std::cout << "ClapTrap " << Name << " destructed!" << std::endl;}

// Setters
void ClapTrap::setName(std::string Name)
{
    this->Name = Name;
    return ;
}
void ClapTrap::setHitPoints(int hitPoints)
{
    this->hitPoints = hitPoints;
    return ;
}
void ClapTrap::setEnergyPoints(int energyPoints)
{
    this->energyPoints = energyPoints;
    return ;
}
void ClapTrap::setAttackDamage(int attackDamage)
{
    this->attackDamage = attackDamage;
    return ;
}

// Getters
std::string ClapTrap::getName() {return Name;}
int ClapTrap::getEnergyPoints() {return energyPoints;}
int ClapTrap::getHitPoints() {return hitPoints;}
int ClapTrap::getAttackDamage() {return attackDamage;}

// Member Functions

void ClapTrap::attack(const std::string& target)
{
    if (!hitPoints)
    {
        std::cout << "ClapTrap " << Name << " No hit points. Can't do anything" << std::endl;
        return ;
    }
    if (!energyPoints)
    {
        std::cout << "ClapTrap " << Name << " No energy points. Can't do anything" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << Name << " attacks " << target 
              << " causing " << attackDamage << " points of damage!"
              << std::endl;
    energyPoints -= 1;
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
    if (amount >= (unsigned int)hitPoints)
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << Name << " takes" << amount 
                  << "points of damage and dies"
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
     if (!hitPoints)
    {
        std::cout << "ClapTrap " << Name << " No hit points. Can't be repaired" << std::endl;
        return ;
    }
    if (!energyPoints)
    {
        std::cout << "ClapTrap " << Name << " No energy points. Can't be repaired" << std::endl;
        return ;
    }
    hitPoints += amount;
    std::cout << "ClapTrap " << Name << " is repaired by " << amount 
              << " points" << std::endl;
    energyPoints -= 1;
    return ;
}