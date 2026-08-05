#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class AForm;   // Forward declaration 
              // pour eviter la dependance circulaire

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw(){return "Grade is too high";}
                
                // Quand quelqu'un demande le message de cette exception, 
                // retourne cette chaîne, sans modifier l'objet 
                // et sans lancer une nouvelle exception
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw(){return "Grade is too low";}
        };

        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& src);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        
        void signForm(AForm& f);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif