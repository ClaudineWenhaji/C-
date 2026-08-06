#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

// The goal of this class is to discover the Factory Pattern, 
// a common design pattern that allows to create different types of objects 
// through a single interface, without the calling code needing 
// to know the concrete type of the object being created.

class Intern
{
    public:

        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& src);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif

//              Bureaucrat
//                   │
//              sign a form
//                   │
//                   ▼
//                AForm
//                   ▲
//       ┌───────────┼────────────┐
//       │           │            │
//  Shrubbery   Robotomy   Presidential
//       │           │            │
//       └───────────┴────────────┘
//                   ▲
//                   │
//                Intern
//        creates the appropriate form