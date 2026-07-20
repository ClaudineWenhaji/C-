/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:29:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/20 17:43:02 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	// with DiamondTrap
	
    std::cout << "=== Creating DiamondTrap ===" << std::endl;
	
	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;
	
    DiamondTrap d("Diamond");

	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;

    d.whoAmI();        // Shows both names
    d.attack("Enemy"); // Uses ScavTrap's attack
    d.guardGate();     // Inherited from ScavTrap
    d.highFivesGuys(); // Inherited from FragTrap

	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;
    std::cout << "=== End of main ===" << std::endl;
    return 0;
}