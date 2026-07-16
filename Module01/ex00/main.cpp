/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:15:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/26 09:46:37 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::cout << "...Zombie's creation on HEAP..." << std::endl;
    
    Zombie* heapZombie;
    
    heapZombie = newZombie("Foo");
    heapZombie->announce();
    delete heapZombie;
    
    std::cout << "...Zombie's Creation on STACK..." << std::endl;
    
    randomChump("Foo");
    
    return (0);
}