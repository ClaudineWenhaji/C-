/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:09:07 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/17 16:27:27 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "...Zombie's creation on HEAP..." << std::endl;
    
    int     N = 4;
    Zombie* nHeapZombies = zombieHorde(N, "Maya");
    
    for (int i = 0; i < N; i++)
        nHeapZombies[i].announce();
    delete[] nHeapZombies;
    
    return (0);
}