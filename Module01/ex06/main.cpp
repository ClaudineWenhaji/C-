/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:47:47 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/26 11:10:04 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Argument's problem. Usage: ./harlFilter level" 
                  << std::endl;
        return (1);
    }
    
    Harl harl_test;
    harl_test.complain(av[1]);
    return (0);
}