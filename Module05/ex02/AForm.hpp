/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:25:38 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/24 12:20:59 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat; // Forward declaration 
                  // pour eviter la dependance circulaire

// AForm now is generic (only the base) that won't be instantiate, not useful to use a generic form
// instead we want to use ShrubberyCreationForm, RobotomyRequestForm 
// & PresidentialPardonForm

class AForm // Abstract class
{
    private:
        const std::string name;
        bool _signed;
        const int gradeToSign;
        const int gradeToExecute;

    public:

        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& src);
        AForm& operator=(const AForm& src);
        virtual ~AForm();

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw(){return "Grade is too high";}
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw(){return "Grade is too low";}
        };
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw(){return "Form not signed!";}
        };

        const std::string& getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& bureau);

        virtual void execute(Bureaucrat const& executor) const = 0; 
        // pure virtual fonction

    protected:
        void checkExecutability(Bureaucrat const& executor) const; 
        // check helper 
        // before executing, check whether the form is signed 
        // and if bureaucrat grade is high

};

std::ostream& operator<<(std::ostream& str, const AForm& f);

#endif