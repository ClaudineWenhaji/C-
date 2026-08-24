/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:26:54 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/24 13:01:24 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <ctime>

int main() 
{
    std::cout << std::endl;
    std::cout << BLUE << "********* CONSTRUCTION ***********" << RESET << std::endl;
    std::cout << std::endl;

    Bureaucrat boss("Boss", 1);

    Intern factory;

    std::cout << std::endl;
    std::cout << GREEN << "********* Shrubbery Form ***********" << RESET << std::endl;
    std::cout << std::endl;

    AForm* form1 = factory.makeForm("shrubbery creation", "garden");

    std::cout << std::endl;
    std::cout << GREEN << "********* Robotomy Form ***********" << RESET << std::endl;
    std::cout << std::endl;

    AForm* form2 = factory.makeForm("robotomy request", "Bender");

    std::cout << std::endl;
    std::cout << GREEN << "********* Presidential Form ***********" << RESET << std::endl;
    std::cout << std::endl;

    AForm* form3 = factory.makeForm("presidential pardon", "Ford");

    std::cout << std::endl;
    std::cout << GREEN << "********* Invalid Form ***********" << RESET << std::endl;
    std::cout << std::endl;

    AForm* form4 = factory.makeForm("invalid form", "test");  // NULL

    std::cout << std::endl;
    std::cout << YELLOW << "********* TESTS: Sign & Execute ***********" << RESET << std::endl;
    std::cout << std::endl;

    if (form1) 
    {
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }
    
    std::cout << std::endl;

    if (form2) 
    {
        boss.signForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }

    std::cout << std::endl;

    if (form3) 
    {
        boss.signForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    if (form4) 
    {
        boss.signForm(*form4);
        boss.executeForm(*form4);
        delete form4;
    }

    std::cout << std::endl;
    std::cout << RED << "********* DESTRUCTION ***********" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}