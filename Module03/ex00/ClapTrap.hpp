#ifndef CLASSTRAP_HPP
# define CLASSTRAP_HPP

#include <iostream>

class ClapTrap{

    private:
        std::string Name;
        int hitPoints;
        int energyPoints;
        int attackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string Name);
        ClapTrap(const ClapTrap& src);
        ClapTrap& operator=(const ClapTrap& src);
        ~ClapTrap();

        std::string getName();
        int getHitPoints();
        int getEnergyPoints();
        int getAttackDamage();

        void setName(std::string Name);
        void setHitPoints(int hitPoints);
        void setEnergyPoints(int energyPoints);
        void setAttackDamage(int attackDamage);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};

#endif