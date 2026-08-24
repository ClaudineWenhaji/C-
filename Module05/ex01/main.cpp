/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:25:28 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/24 12:59:07 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Colors.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << GREEN << "********* TEST1: A Form with grade too high or too low ***********" << RESET << std::endl;
    std::cout << std::endl; 

    try
    {
        Form A("Claudine", 0, 5);
        std::cout << YELLOW << A << RESET<< std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    try
    {
        Form A("Claudine", 1, 156);
        std::cout << YELLOW << A << RESET<< std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    std::cout << GREEN << "********* TEST2: Create a form & try to sign ***********" << RESET << std::endl;
    std::cout << std::endl; 

    try
    {
        Bureaucrat claudine("Claudine", 15);
        Form form("Bob", 20, 45);
        std::cout << std::endl;

        std::cout << claudine << std::endl;
        std::cout << form << std::endl;
        std::cout << std::endl;

        claudine.signForm(form);
        std::cout << form << std::endl;
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << RED << "Exception: " <<  e.what() << RESET << '\n';
    }
    std::cout << std::endl;
    
    std::cout << GREEN << "********* TEST3: A Form & try to sign but grade is not enough ***********" << RESET << std::endl;
    std::cout << std::endl; 
    try
    {
        Bureaucrat out("Claudine", 35);
        Form form1("Bob", 30, 45);
        std::cout << std::endl;

        std::cout << out << std::endl;
        std::cout << form1 << std::endl;
        std::cout << std::endl;

        out.signForm(form1);
        std::cout << form1 << std::endl;
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " <<  e.what() << RESET << '\n';
    }
    std::cout << std::endl;    

    return 0;
}