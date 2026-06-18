/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:47:47 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/18 16:04:02 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

// Convert string to index for switch
int convert_str_to_index(const std::string& level) 
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) {
        if (level == levels[i])
            return i;
    }
    return -1;  // Not found
}

int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << "Argument's problem" << std::endl;
    
    std::string level = av[1];
    Harl harl;
    int levelIdx = convert_str_to_index(level)
    
    switch (convert_str_to_index(av[i]))
    {
    case constant expression:
        /* code */
        break;
    
    default:
        break;
    }
}