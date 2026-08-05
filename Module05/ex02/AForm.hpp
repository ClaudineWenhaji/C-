#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat; // Forward declaration 
                  // pour eviter la dependance circulaire

class AForm
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
                const char* what() const throw(){return "Form not signed: grade is not enough!";}
        };

        const std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& bureau);

        virtual const void execute(Bureaucrat const& executor) = 0; 
        // pure virtual fonction

    protected:
        void checkExecutability(Bureaucrat const& executor) const; // check helper 

};

std::ostream& operator<<(std::ostream& str, const AForm& f);


#endif