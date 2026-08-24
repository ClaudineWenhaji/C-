/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:26:11 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/24 10:26:12 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm is constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    : AForm::AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCretionForm copy constructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    if (this != &src)
        _target = src._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){std::cout << "ShrubberyCreationForm is destructed" << std::endl;}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    checkExecutability(executor); // check if form can be executed

    // create output file: target_shrubbery
    std::string outfile = _target + "_shrubbery";
    std::ofstream file(outfile.c_str());

    if (!file.is_open())
        throw std::runtime_error("cannot create file");
    
    // write ascii trees to file
    file << "       *"      << std::endl;
    file << "      ***"     << std::endl;
    file << "     *****"    << std::endl;
    file << "    *******"   << std::endl;
    file << "   *********"  << std::endl;
    file << "  ***********" << std::endl;
    file << "       |"      << std::endl;

    file.close();
    std::cout << executor.getName() << " successfully created a shrubbery" << std::endl;
}

std::ostream& operator<<(std::ostream& str, const ShrubberyCreationForm& f)
{
    str << f.getName()
       << " form is signed? " << (f.isSigned() ? "yes" : "no")
       << ", sign grade " << f.getGradeToSign()
       << ", exec grade " << f.getGradeToExecute();
    return str;
}