#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <exception>
#include <string>

class RobotomyRequestForm : public AForm
{
    private:
        const std::string Module05;

    public:
        RobotomyRequestForm(const std::string& Module05);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm& operator=(RobotomyRequestForm const& src);
        ~RobotomyRequestForm();
};

#endif