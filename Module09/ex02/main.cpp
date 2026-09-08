/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:49:56 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/08 12:10:27 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error Usage like: ./RPN \"1 9 - 4 - 1 +\"" << std::endl;
        return 1;
    }

    RPN calculator;
    
    try
    {
       
       int result = calculator.evaluate(av[1]);
       std::cout << result << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;   
}