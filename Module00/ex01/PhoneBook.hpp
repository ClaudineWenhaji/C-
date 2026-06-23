/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:51:40 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/23 18:50:04 by clwenhaj         ###   ########.fr       */
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
   int currentIndex;
   int countContact;

public:
   PhoneBook();  
   ~PhoneBook(); 

   void addContact(); 
   std::string formatColumn(const std::string& str) const;
   int isNumber(const std::string& str) const;
   void searchContact() const; 
};

#endif
