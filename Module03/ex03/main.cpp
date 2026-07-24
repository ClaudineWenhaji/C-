/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:29:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/24 17:23:09 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	// with DiamondTrap
    
    std::cout << "=== Creating DiamondTrap ===\n\n";

    DiamondTrap d("Diamond");

    std::cout << "\n--------------------------\n\n";

    d.whoAmI();
    d.attack("Enemy");
    d.guardGate();
    d.highFivesGuys();

    std::cout << "\n--------------------------\n\n";

    std::cout << "=== Copy constructor ===" << std::endl;
    DiamondTrap copy(d);
    copy.whoAmI();

    std::cout << "\n--------------------------\n\n";

    std::cout << "=== Assignment operator ===" << std::endl;
    DiamondTrap other("Other");
    other = d;
    other.whoAmI();

    std::cout << "\n--------------------------\n\n";
    std::cout << "=== End of main ===" << std::endl;
}