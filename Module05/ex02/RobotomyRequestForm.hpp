#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <exception>
#include <string>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm& operator=(RobotomyRequestForm const& src);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& str, const RobotomyRequestForm& f);

#endif