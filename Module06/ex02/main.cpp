/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:30:01 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/27 17:49:42 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include "Colors.hpp"

class E : public Base {};

int main()
{
    std::cout << std::endl;
    std::cout << GREEN << "GOOD" << RESET << std::endl;
    
    Base* derivedClass = generate();
    identify(derivedClass);
    identify(*derivedClass);

    std::cout << std::endl;
    std::cout << RED << "WRONG" << RESET << std::endl;
   
    Base* wrongClass = new E;
    identify(wrongClass);
    identify(*wrongClass);
    std::cout << std::endl;
    
    return (0); 
}