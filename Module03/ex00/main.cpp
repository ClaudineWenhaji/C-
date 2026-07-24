/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:29:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/24 12:40:15 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << std::endl << "----- Constructor calls -----" << std::endl;
	
	ClapTrap a("Hero");
	
	std::cout << std::endl;

    std::cout << "ClapTrap Hit Points: " << a.getHitPoints() << std::endl;
    std::cout << "ClapTrap Energy Points: " << a.getEnergyPoints() << std::endl;
    std::cout << "ClapTrap Attack Damage: " << a.getAttackDamage() << std::endl;

	std::cout << std::endl;
	
    a.attack("Enemy");
    a.beRepaired(5);
	a.takeDamage(3);

	std::cout << std::endl << "----- Destructor calls -----" << std::endl;
	return (0);	
}