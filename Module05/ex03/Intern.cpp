#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(){}
Intern::Intern(const Intern& copy){(void)copy;}
Intern& Intern::operator=(const Intern& src)
{
    (void)src;
    return *this;
}
Intern::~Intern(){};

static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)

{return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

typedef AForm* (*Formcreator)(const std::string&);

AForm *Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    Formcreator creators[] = {createShrubbery, createRobotomy, createPresidential};

    for (int i = 0; i < 3; i++)
    {
        if (form_names[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }

    }
    std::cerr << "Intern can't create form: " << formName << " not found" << std::endl;
    return NULL;
}

    // AForm* (*creator)(const std::string&);
    // Return type (*pointer_name)(parameter types)
   
    // Array of function pointers
    // AForm* (*creators[3])(const std::string&)

    // Assigning a function to the pointer
    // creator = &createShrubbery;  // or creator = createShrubbery;

    // Calling through the pointer
    // AForm* form = creator(target);  // or: (*creator)(target);

