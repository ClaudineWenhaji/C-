/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:26:45 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/25 11:55:30 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern& copy)
{
    (void)copy;
}
Intern& Intern::operator=(const Intern& src) // operateur d'affectation
{
    (void)src;
    return *this; // l'operateur = doit retourner une reference vers l'objet courant
}
Intern::~Intern() {};

// ***** Trois fonctions intermediaires de fabrication des 3 formulaires

static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
    // recoit target et retourne new ShrubberyCreationForm(target)
    // qui est un AForm* qui est un pointeur
}

static AForm* createRobotomy(const std::string& target)

{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}
// *******************************************************

typedef AForm* (*Formcreator)(const std::string&);
// *Formcreator  est un pointeur vers une fonction (creator)
// qui prend en arguments un const std::string et retourne un AForm*
// Va aider pour la factory
// Formcreator creator equivaut a AForm* (*creator)(const std::string&)

AForm *Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    // tableau de strings

    Formcreator creators[] = {
        createShrubbery, 
        createRobotomy, 
        createPresidential};
    // tableau de fonctions ou encore
    // tableau des pointeurs vers des fonctions
    

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

