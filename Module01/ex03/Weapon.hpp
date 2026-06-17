/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:05:45 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/17 17:23:44 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon{
private:
    std::string _type;
public:
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType(void) const;
    void setType(const std::string &newtype);
};

#endif