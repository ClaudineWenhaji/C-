/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:03:31 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/05/23 13:27:31 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
      // std::cout << "Constructor called" << std::endl;
}

Contact::~Contact()
{
      // std::cout << "Destructor called" << std::endl;
}

int Contact::ft_isValidPhoneNumber(const std::string& str) const
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return 0; 
    }
    return 1; 
}

int Contact::ft_isAlpha(const std::string& str) const
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isalpha(str[i]))
            return 0; 
    }
    return 1; 
}

void Contact::setFirstName(std::string str)
{
    if (!str.empty() && this->ft_isAlpha(str))
        this->firstName = str;
    else
        std::cout << "Invalid first name. Please enter a valid first name." << std::endl;
}

void Contact::setLastName(std::string str)
{
    if (!str.empty() && this->ft_isAlpha(str))
      this->lastName = str;
    else
        std::cout << "Invalid last name. Please enter a valid last name." << std::endl;
}

void Contact::setNickName(std::string str)
{
    if (!str.empty() && this->ft_isAlpha(str))
        this->nickName = str;
    else
        std::cout << "Invalid nickname. Please enter a valid nickname." << std::endl;
}

void Contact::setPhoneNumber(std::string str)
{
    if (!str.empty() && this->ft_isValidPhoneNumber(str))
        this->phoneNumber = str;
    else
    {
        std::cout << "Invalid phone number. Please enter a valid phone number." << std::endl;
    }
}

void Contact::setDarkestSecret(std::string str)
{
    if (!this->darkestSecret.empty())
    {
        std::cout << "Darkest secret already set. Cannot overwrite existing secret." << std::endl;
        return;
    }
    this->darkestSecret = str;
}

std::string Contact::getFirstName() const
{
      return this->firstName;
}

std::string Contact::getLastName() const
{
      return this->lastName;
}

std::string Contact::getNickName() const
{
      return this->nickName;
}

std::string Contact::getPhoneNumber() const
{
      return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return this->darkestSecret;
}

