/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:48:48 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/17 16:28:20 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *nHordes;
    
    if (N <= 0)
        return NULL;
        
    nHordes = new Zombie[N];
    
    for (int i = 0; i < N; i++)
        nHordes[i].setName(name);
    return nHordes;
}