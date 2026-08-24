/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:25:53 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/24 12:58:57 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <ctime>

int main() 
{
    std::cout << std::endl;
    std::srand(std::time(NULL));

    std::cout << YELLOW << "********* CLASSES' CONSTRUCTION ***********" << RESET << std::endl;
    std::cout << std::endl;

    Bureaucrat president("President", 1);
    Bureaucrat clerk("Clerk", 140);
    std::cout << std::endl;

    ShrubberyCreationForm shrub("Module05");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Ford");
    std::cout << std::endl;

    // Try to execute unsigned forms
    std::cout << RED << "********* TEST1: Try to execute unsigned form ***********" << RESET << std::endl;
    std::cout << std::endl;

    president.executeForm(shrub);  // Fails: not signed
    std::cout << std::endl;

    // Sign and execute
    std::cout << GREEN << "********* TEST2: Sign & Execute ***********" << RESET << std::endl;
    std::cout << std::endl;

    president.signForm(shrub);
    president.executeForm(shrub);  // Creates Module05_shrubbery file
    std::cout << std::endl;

    std::cout << RED << "********* TEST3: Sign & Execute: Grade too LOW ***********" << RESET << std::endl;
    std::cout << std::endl;
    
    clerk.signForm(robot);     // Fails: grade too low
    std::cout << std::endl;

    std::cout << YELLOW << "********* TEST4: Robotomy 50% of the time ***********" << RESET << std::endl;
    std::cout << std::endl;
    // robotomy succeeds only 50% of the time, 
    // it's customary to execute it multiple times:

    for (int i = 0; i < 3; i++)
    {
        president.signForm(robot);
        president.executeForm(robot);
         std::cout << std::endl;
    }

    std::cout << GREEN << "********* TEST5: Presidential Pardon ***********" << RESET << std::endl;
    std::cout << std::endl;

    president.signForm(pardon);
    president.executeForm(pardon);
    std::cout << std::endl;

    std::cout << RED << "********* TEST6: Execute grade too low ***********" << RESET << std::endl;
    std::cout << std::endl;
    // Since ShrubberyCreationForm requires grade 137 to execute 
    // and the clerk is 140, this should throw.

    president.signForm(shrub);
    clerk.executeForm(shrub);
    std::cout << std::endl;

    std::cout << RED << "********* CLASSES' DESTRUCTION ***********" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}