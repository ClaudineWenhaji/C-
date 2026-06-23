/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:25:19 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/23 17:55:56 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int	i = 1;
		while (av[i])
		{
			{
				int	j = 0;
				while (av[i][j])
				{
					std::cout << (char)std::toupper(av[i][j]);
					j++;
				}
			}
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
				  << std::endl;
	return (0);
}
