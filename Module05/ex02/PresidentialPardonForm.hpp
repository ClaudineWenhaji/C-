#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm& operator=(PresidentialPardonForm const& src);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& str, const PresidentialPardonForm& f);

#endif