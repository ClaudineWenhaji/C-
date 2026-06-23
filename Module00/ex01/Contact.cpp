/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:03:31 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/23 18:28:01 by clwenhaj         ###   ########.fr       */
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

int Contact::setFirstName(std::string str)
{
    if (!str.empty() && this->ft_isAlpha(str))
    {
        this->firstName = str;
        return 1;
    }
    return 0;
}

int Contact::setLastName(std::string str)
{
    if (!str.empty() && this->ft_isAlpha(str))
    {
        this->lastName = str;
        return 1;
    }
    return 0;   
}

int Contact::setNickName(std::string str)
{
    if (!str.empty() && this->ft_isAlpha(str))
    {                   
        this->nickName = str;
        return 1;
    }
    return 0;
}

int Contact::setPhoneNumber(std::string str)
{
    if (!str.empty() && this->ft_isValidPhoneNumber(str))
    {
        this->phoneNumber = str;
        return 1;
    }
    return 0;   
}

int Contact::setDarkestSecret(std::string str)
{
    this->darkestSecret = str;
    return 1;
}

// GETTERS

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

