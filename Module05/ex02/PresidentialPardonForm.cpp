#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm is constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
    : AForm::AForm(copy), _target(copy._target)
{
    std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& src)
{
    if (this != &src)
        _target = src._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){std::cout << "PresidentialPardonForm is destructed" << std::endl;}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    (void)executor;
    std::cout << _target
              << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
}

std::ostream& operator<<(std::ostream& str, const PresidentialPardonForm& f)
{
    str << f.getName()
       << " form is signed? " << (f.isSigned() ? "yes" : "no")
       << ", sign grade " << f.getGradeToSign()
       << ", exec grade " << f.getGradeToExecute();
    return str;
}