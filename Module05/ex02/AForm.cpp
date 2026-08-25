/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:25:35 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/25 12:08:58 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
    : name(name), _signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "AForm is constructed!" << std::endl;

    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& src)
    : name(src.name), _signed(src._signed), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    std::cout << "AForm Copy constructed" << std::endl;
}

AForm& AForm::operator=(const AForm& src)
{
    if (this != &src)
        _signed = src._signed; // only the signed status can change
    return *this;
}

AForm::~AForm(){std::cout << "AForm is destructed!" << std::endl;}

const std::string& AForm::getName() const {return name;}
bool AForm::isSigned() const {return _signed;}
int AForm::getGradeToSign() const{return gradeToSign;}
int AForm::getGradeToExecute() const{return gradeToExecute;}

void AForm::beSigned(const Bureaucrat& bureau)
{
    if (bureau.getGrade() > gradeToSign)
        throw (AForm::GradeTooLowException());
    _signed = true;
}

void AForm::checkExecutability(Bureaucrat const& executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& str, const AForm& f)
{
    str << f.getName()
       << " form is signed? " << (f.isSigned() ? "yes" : "no")
       << ", sign grade " << f.getGradeToSign()
       << ", exec grade " << f.getGradeToExecute();
    return str;
}