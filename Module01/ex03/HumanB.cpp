/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:14:56 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/17 19:11:57 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)  : _name(name), _weapon(NULL){}

HumanB::~HumanB(){}

void HumanB::attack()
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with " 
                  << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon";
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}