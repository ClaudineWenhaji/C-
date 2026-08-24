/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:25:21 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/24 10:25:22 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : name(name), _signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Form is constructed!" << std::endl;

    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& src)
    : name(src.name), _signed(src._signed), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    std::cout << "Form Copy constructed" << std::endl;
    *this = src;
}

Form& Form::operator=(const Form& src)
{
    if (this != &src)
        _signed = src._signed; // only the signed status can change
    return *this;
}

Form::~Form(){std::cout << "Form is destructed!" << std::endl;}

const std::string& Form::getName() const {return name;}
bool Form::isSigned() const {return _signed;}
int Form::getGradeToSign() const{return gradeToSign;}
int Form::getGradeToExecute() const{return gradeToExecute;}

void Form::beSigned(const Bureaucrat& bureau)
{
    if (bureau.getGrade() > gradeToSign)
        throw (Form::GradeTooLowException());
    _signed = true;
}

std::ostream& operator<<(std::ostream& str, const Form& f)
{
    str << f.getName()
       << " form is signed? " << (f.isSigned() ? "yes" : "no")
       << ", sign grade " << f.getGradeToSign()
       << ", exec grade " << f.getGradeToExecute();
    return str;
}