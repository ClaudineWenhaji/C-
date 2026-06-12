/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:02:57 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/11 16:07:23 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->currentIndex = 0;
}

PhoneBook::~PhoneBook()
{
      
}

void PhoneBook::addContact()
{
      std::string input;
      
      while (1)
      {
            std::cout << "Enter first name: ";
            std::getline(std::cin, input);
            if (!input.empty() && this->contacts[this->currentIndex].setFirstName(input))
                  break;
            else
                  std::cout << "Invalid first name. Please enter a valid first name." << std::endl;
      }
      while (1)
      {
            std::cout << "Enter last name: ";
            std::getline(std::cin, input);
            if (!input.empty() && this->contacts[this->currentIndex].setLastName(input))
                  break;
            else
                  std::cout << "Invalid last name. Please enter a valid last name." << std::endl;
      }
      while (1)
      {
            std::cout << "Enter nickname: ";
            std::getline(std::cin, input);
            if (!input.empty() && this->contacts[this->currentIndex].setNickName(input))
                  break;
            else
                  std::cout << "Invalid nickname. Please enter a valid nickname." << std::endl;
      }
      while (1)
      {
            std::cout << "Enter phone number: ";
            std::getline(std::cin, input);
            if (!input.empty() && this->contacts[this->currentIndex].setPhoneNumber(input))
                  break;
            else
                  std::cout << "Invalid phone number. Please enter only a digit number." << std::endl;
      }
      while (1)
      {
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, input);
            if (!input.empty() && this->contacts[this->currentIndex].setDarkestSecret(input))
                  break;
            else
                  std::cout << "Invalid darkest secret. Please enter a valid darkest secret." << std::endl;
      }
      this->currentIndex++;
      this->currentIndex = this->currentIndex % 8; // Permet de réutiliser les indices de 0 à 7
}

std::string PhoneBook::formatColumn(const std::string& str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

int PhoneBook::isNumber(const std::string& str) const
{
      if (str.empty())
            return 0;
      for (size_t i = 0; i < str.length(); ++i)
      {
            if (!std::isdigit(str[i]))
                  return 0;
      }
      return 1;
}
void PhoneBook::searchContact() const
{      
      std::cout << std::setw(10) << "Index" << " | "
                << std::setw(10) << "First Name" << " | "
                << std::setw(10) << "Last Name" << " | "
                << std::setw(10) << "Nickname" 
                << std::endl;
      int i = 0;
      while (i < 8)
      {
            if (this->contacts[i].getFirstName() != "")
            {
                  std::cout << std::setw(10) << i << " | "
                  << std::setw(10) << formatColumn(this->contacts[i].getFirstName()) << " | "
                  << std::setw(10) << formatColumn(this->contacts[i].getLastName()) << " | "
                  << std::setw(10) << formatColumn(this->contacts[i].getNickName())
                  << std::endl;
            }
            i++;
      }
      std::cout << "Enter the index of the contact to view details: ";
      std::string input;
      std::getline(std::cin, input);
      if (!isNumber(input))
      {
            std::cout << "Invalid input. Please enter a valid index number." << std::endl;
            return;
      }
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
            std::cout << "Index out of bounds. No contact found." << std::endl;
}