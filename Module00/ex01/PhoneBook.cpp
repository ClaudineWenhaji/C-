/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:02:57 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/05/23 13:47:44 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->currentIndex = 0;
        // std::cout << "Constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
      // std::cout << "Destructor called" << std::endl;
}

void PhoneBook::addContact()
{
      if (this->currentIndex >= 8)
      {
            std::cout << "PhoneBook is full. Cannot add more contacts." << std::endl;
            return;
      }
      std::string input;

      std::cout << "Enter first name: ";
      std::getline(std::cin, input);
      this->contacts[this->currentIndex].setFirstName(input);

      std::cout << "Enter last name: ";
      std::getline(std::cin, input);
      this->contacts[this->currentIndex].setLastName(input);

      std::cout << "Enter nickname: ";
      std::getline(std::cin, input);
      this->contacts[this->currentIndex].setNickName(input);

      std::cout << "Enter phone number: ";
      std::getline(std::cin, input);
      this->contacts[this->currentIndex].setPhoneNumber(input);

      std::cout << "Enter darkest secret: ";
      std::getline(std::cin, input);
      this->contacts[this->currentIndex].setDarkestSecret(input);

      this->currentIndex++;
      this->currentIndex = this->currentIndex % 8; // Permet de réutiliser les indices de 0 à 7
}

void PhoneBook::searchContact() const
{
      std::cout << "Index | First Name | Last Name | Nickname" << std::endl;
      
      std::cout << std::setw(10) << "Index" << " | "
                << std::setw(10) << "First Name" << " | "
                << std::setw(10) << "Last Name" << " | "
                << std::setw(10) << "Nickname" << std::endl;
      int i = 0;
      while (i < 8)
      {
            if (this->contacts[i].getFirstName() != "")
            {
                  std::cout << std::setw(10) << i << " | "
                  << std::setw(10) << this->contacts[i].getFirstName() << " | "
                  << std::setw(10) << this->contacts[i].getLastName() << " | "
                  << std::setw(10) << this->contacts[i].getNickName()
                  << std::endl;
            }
            i++;
      }
        std::cout << "Enter the index of the contact to view details: ";
        std::string input;
        std::getline(std::cin, input);
        int index = atoi(input.c_str()); 
        if (index >= 0 && index < 8 && this->contacts[index].getFirstName() != "")
        {
            std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
            std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
            std::cout << "Nickname: " << this->contacts[index].getNickName() << std::endl;
            std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
        }
        else
        {
            std::cout << "Invalid index. No contact found." << std::endl;
        }
}