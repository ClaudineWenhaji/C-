/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:29:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/20 16:42:13 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap clap("Clappy");
	std::cout << "ClapTrap Name: " << clap.getName() << std::endl;
    std::cout << "ClapTrap Hit Points: " << clap.getHitPoints() << std::endl;
    std::cout << "ClapTrap Energy: " << clap.getEnergyPoints() << std::endl;
    std::cout << "ClapTrap Attack: " << clap.getAttackDamage() << std::endl;

	clap.attack("enemy");  // "ClapTrap Clappy attacks enemy"
	clap.takeDamage(3);
	clap.beRepaired(6);
	
	std::cout << "-------------------" << std::endl;
	std::cout << std::endl;
	
	ScavTrap scav("Scavy");
	std::cout << "ScavTrap Name: " << scav.getName() << std::endl;
    std::cout << "ScavTrap Hit Points: " << scav.getHitPoints() << std::endl;
    std::cout << "ScavTrap Energy: " << scav.getEnergyPoints() << std::endl;
    std::cout << "ScavTrap Attack: " << scav.getAttackDamage() << std::endl;
	
	scav.attack("enemy");  // "ScavTrap Scavvy attacks enemy"
	scav.takeDamage(4);
	scav.beRepaired(5);

	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;
	
	FragTrap frag("Fragy");
	std::cout << "FragTrap Name: " << frag.getName() << std::endl;
    std::cout << "FragTrap Hit Points: " << frag.getHitPoints() << std::endl;
    std::cout << "FragTrap Energy: " << frag.getEnergyPoints() << std::endl;
    std::cout << "FragTrap Attack: " << frag.getAttackDamage() << std::endl;
	
	frag.attack("enemy");  // "FragTrap Fragy attacks enemy"
	frag.takeDamage(10);
	frag.beRepaired(15);
	frag.highFivesGuys();

	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;
	
	return (0);	
}