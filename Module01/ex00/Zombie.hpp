/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:16:17 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/17 16:01:31 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string _name;
    
public:
    Zombie(std::string name);
    ~Zombie();
    
    void announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif