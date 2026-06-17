/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:30:08 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/17 19:09:17 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
private:
    std::string _name;
    Weapon& _weapon;
public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    void attack() const;
};

#endif