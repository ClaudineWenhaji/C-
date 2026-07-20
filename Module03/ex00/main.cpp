/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:29:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/20 12:29:51 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::string hero_name = "Hero";
	std::string villain_name = "NoHero";

	std::cout << std::endl << "----- Constructor calls -----" << std::endl;
	ClapTrap hero(hero_name);
	ClapTrap villain(villain_name);

	std::cout << std::endl << "----- Member function calls -----" << std::endl;
    std::cout << "************************************" << std::endl;

	std::cout << hero.getName() << " is so smart, first thing they do is to repair themselves." << std::endl;
	hero.beRepaired(10);
	std::cout << "----------" << std::endl;
	std::cout << villain.getName() << " just wants to attack." << std::endl;
	std::cout << "----------" << std::endl;

	villain.attack(hero.getName());
	std::cout << "----------" << std::endl;

	std::cout << hero.getName() << " now attacks" << std::endl;
	hero.attack(villain.getName());
	
	std::cout << "----------" << std::endl;
	std::cout << "None of them have any attack damage points! This will be a never ending fight!" << std::endl;
	std::cout << "----------" << std::endl;
	villain.takeDamage(hero.getAttackDamage());
	std::cout << "In anger, " << villain.getName() << " attacked 4 times in a row!" << std::endl;
	std::cout << "----------" << std::endl;
	for (int i = 0; i < 4; i++)
		villain.attack(hero.getName());
	std::cout << "----------" << std::endl;
	std::cout << hero.getName() << " didn't feel even an itch." << std::endl;
	std::cout << villain.getName() << " is so tired, they can't attack anymore." << std::endl;
	villain.attack(hero.getName());
	std::cout << hero.getName() << " won!" << std::endl;
	
	std::cout << std::endl << "----- Destructor calls -----" << std::endl;
	return (0);	
}