#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() throw(){return "Grade is too high";}
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() throw(){return "Grade is too low";}
        };

        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& src);
        ~Bureaucrat();

        const std::string getName();
        int getGrade();

        void incrementGrade();
        void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif