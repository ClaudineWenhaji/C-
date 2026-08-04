#include "Form.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : name(name), _signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructed!" << std::endl;

    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& src)
    : name(src.name), _signed(src._signed), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    std::cout << "Copy constructed" << std::endl;
}

Form& Form::operator=(const Form& src)
{
    if (this != &src)
    {
        _signed = src._signed; // only the signed status can change
    }
    return *this;
}

Form::~Form(){std::cout << "Form destructed!" << std::endl;}

const std::string Form::getName() const {return name;}
bool Form::isSigned() const {return _signed;}
int Form::getGradeToSign() const{return gradeToSign;}
int Form::getGradeToExecute() const{return gradeToExecute;}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooHighException();
    _signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form " << f.getName()
       << "[is signed: " << (f.isSigned() ? "yes" : "no")
       << ", sign grade " << f.getGradeToSign()
       << ", exec grade " << f.getGradeToExecute() << "]";
    return os;
}