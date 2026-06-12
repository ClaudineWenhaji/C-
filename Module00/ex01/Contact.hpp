/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:48:17 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/05/26 11:40:11 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class	Contact
{
private:
      std::string firstName;
      std::string lastName;
      std::string nickName;
      std::string phoneNumber;
      std::string darkestSecret;

      int ft_isValidPhoneNumber(const std::string& str) const;
      int ft_isAlpha(const std::string& str) const;
      
public:
      Contact(); 
      ~Contact(); 
      
      // Setters ou mutateurs qui permettent 
      // de modifier les attributs (ou donnees) de la classe Contact
      int setFirstName(std::string str);
      int setLastName(std::string str);
      int setNickName(std::string str);
      int setPhoneNumber(std::string str);
      int setDarkestSecret(std::string str);
 
      // Getters ou accesseurs qui permettent 
      // d'accéder aux valeurs des attributs de la classe Contact
      std::string getFirstName() const;
      std::string getLastName() const;
      std::string getNickName() const;
      std::string getPhoneNumber() const;
      std::string getDarkestSecret() const;
};

#endif
