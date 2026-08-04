#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

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

        const std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& b);

};

std::ostream& operator<<(std::ostream& os, const Form& f);


#endif