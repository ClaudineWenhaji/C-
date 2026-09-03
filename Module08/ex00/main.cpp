/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:32:14 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/03 16:02:00 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
#include "Colors.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << GREEN << "Test with Vector" << RESET << std::endl;
    
    std::vector<int> vect;

    vect.push_back(1);
    vect.push_back(7);
    vect.push_back(-56);
    vect.push_back(0);
    
    try
    {
        std::vector<int>::iterator it = easyfind(vect, 100);
        std::cout << *it << " found in Vector" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    std::cout << GREEN << "Test with List" << RESET << std::endl;
    
    std::list<int> lst;

    lst.push_back(19); lst.push_back(0); lst.push_back(-1);
    
    try
    {
        std::list<int>::iterator it = easyfind(lst, -1);
        std::cout << *it << " found in List" << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}