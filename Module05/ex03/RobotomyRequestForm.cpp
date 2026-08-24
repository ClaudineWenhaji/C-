/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:27:04 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/24 10:27:05 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm is constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
    : AForm::AForm(copy), _target(copy._target)
{
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
    if (this != &src)
        _target = src._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){std::cout << "RobotomyRequestForm is destructed" << std::endl;}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    checkExecutability(executor); // check if form can be executed

    std::cout << "Bzzzzzzzzzzzzz..... " << std::endl;

    if (std::rand() % 2) // std::rand() retourne un entier pseudo-aleatoire pair ou impair
        std::cout << _target 
                  << " has been robotomized successfully"
                  << std::endl;
    else
        std::cout << "robotomy of " 
                  << _target 
                  << " failed" 
                  << std::endl;
}

std::ostream& operator<<(std::ostream& str, const RobotomyRequestForm& f)
{
    str << f.getName()
       << " form is signed? " << (f.isSigned() ? "yes" : "no")
       << ", sign grade " << f.getGradeToSign()
       << ", exec grade " << f.getGradeToExecute();
    return str;
}