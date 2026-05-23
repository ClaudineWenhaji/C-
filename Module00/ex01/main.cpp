/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:00:04 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/05/23 12:44:45 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
        PhoneBook phoneBook;
        std::string command;
    
        while (true)
        {
                std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
                std::getline(std::cin, command);
    
                if (command == "ADD")
                {
                    phoneBook.addContact();
                }
                else if (command == "SEARCH")
                {
                    phoneBook.searchContact();
                }
                else if (command == "EXIT")
                {
                    std::cout << "Exiting the program." << std::endl;
                    break;
                }
                else
                {
                    std::cout << "Invalid command. Please try again." << std::endl;
                }
        }
    
        return 0;
}
