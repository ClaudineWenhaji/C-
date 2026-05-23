/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:51:40 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/05/23 13:35:06 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>

class	PhoneBook
{
private:
   Contact contacts[8];
   int currentIndex; // Index pour suivre le nombre de contacts ajoutés

public:
   PhoneBook();  // Constructeur par défaut qui initialise les attributs de la classe PhoneBook
   ~PhoneBook(); // Destructeur qui est appelé lorsque l'objet PhoneBook est détruit

   void addContact(); // Méthode pour ajouter un contact à la liste
   void searchContact() const; // Méthode pour rechercher et afficher les contacts dans la liste
};

#endif
