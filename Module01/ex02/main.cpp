/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:35:11 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/17 17:01:57 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main (void)
{
    std::string  str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    /* Memory address*/
    std::cout << "The memory address of the string variable is:  "
              << &str << std::endl;
    std::cout << "The memory address held by stringPTR is: "
              << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF is: "
              << &stringREF << std::endl;

    /* Values */
    std::cout << "The value of the string variable is:  " 
              << str << std::endl;
    std::cout << "The value pointed to by stringPTR is: "
              << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF is: "
              << stringREF << std::endl;
    
    return (0);
}