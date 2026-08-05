#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade)
{
    std::cout << "Bureaucrat is constructed!" << std::endl;

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : name(src.name), grade(src.grade)
{
    std::cout << "Bureaucrat Copy constructed!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    std::cout << "Bureaucrat Operator Assignment" << std::endl;

    if (this != &src)
        grade = src.grade; // cannot change name because it's const
    return *this;
}

Bureaucrat::~Bureaucrat(){std::cout << "Bureaucrat is Destructed!" << std::endl;}

const std::string& Bureaucrat::getName()const 
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}