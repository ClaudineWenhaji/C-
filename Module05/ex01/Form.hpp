/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:25:25 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/24 10:25:26 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat; // Forward declaration 
                  // pour eviter la dependance circulaire

class Form
{
    private:
        const std::string name;
        bool _signed;
        const int gradeToSign;
        const int gradeToExecute;

    public:

        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        Form(const Form& src);
        Form& operator=(const Form& src);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw(){return "Grade is too high";}
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw() {return "Grade is too low";}
        };

        const std::string& getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& bureau); 

};

std::ostream& operator<<(std::ostream& str, const Form& f);


#endif