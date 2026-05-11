/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:25:19 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/05/11 15:16:37 by clwenhaj         ###   ########.fr       */
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
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
