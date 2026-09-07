/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:49:56 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/07 17:49:05 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << " Error: could not open file.";
        return 1;
    }

    try
    {
        BitcoinExchange exchange;
        exchange.processInput(av[1]);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;   
}