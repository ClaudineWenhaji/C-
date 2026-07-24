/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:29:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/24 12:55:53 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << std::endl << "----- Constructor calls -----" << std::endl;
	ClapTrap clap("Clappy");
	std::cout << std::endl;
	
	std::cout << "ClapTrap Name: " << clap.getName() << std::endl;
	std::cout << std::endl;
	
    std::cout << "ClapTrap Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "ClapTrap Energy: " << clap.getEnergyPoints() << std::endl;
    std::cout << "ClapTrap Attack: " << clap.getAttackDamage() << std::endl;
	std::cout << std::endl;
	
	clap.attack("enemy");  // "ClapTrap Clappy attacks enemy"
	clap.takeDamage(3);
	clap.beRepaired(6);
	
	std::cout << std::endl << "----- Constructor calls -----" << std::endl;
	ScavTrap scav("Scavy");
	std::cout << std::endl;
	
	std::cout << "ScavTrap name: " << scav.getName() << std::endl;
	std::cout << std::endl;
	
    std::cout << "ScavTrap Hit Points: " << scav.getHitPoints() << std::endl;
    std::cout << "ScavTrap Energy: " << scav.getEnergyPoints() << std::endl;
    std::cout << "ScavTrap Attack: " << scav.getAttackDamage() << std::endl;
	std::cout << std::endl;
	
	scav.attack("enemy");  // "ScavTrap Scavvy attacks enemy"
	scav.takeDamage(4);
	scav.beRepaired(5);

	std::cout << std::endl;
	
	return (0);	
}