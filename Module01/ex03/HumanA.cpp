/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:54:19 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/17 19:11:51 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) :
        _name(name), _weapon(weapon){}

HumanA::~HumanA(){}
        
void HumanA::attack() const
{
    std::cout << this->_name << " attacks with " 
              << this->_weapon.getType() << std::endl;
}