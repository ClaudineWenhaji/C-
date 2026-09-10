/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 16:49:56 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/10 14:03:06 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error - Usage: " << av[0] << " numbers..." << std::endl;
        return 1;
    }
    
    try
    {
       PMergeMe sorter;
       sorter.ParseInput(ac, av);
       sorter.displayBefore();
       sorter.sort();
       sorter.displayAfter();
       
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;   
}