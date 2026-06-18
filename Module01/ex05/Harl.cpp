/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:47:37 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/18 15:49:51 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
Harl::Harl(void){}
Harl::~Harl(void){}

void Harl::debug(void){
    std::cout << "DEBUG: I love having extra bacon"
                 "for my 7XL-double-cheese-triple-pickle-special-"
                 "ketchup burger. I really do!" 
              << std::endl;}
void Harl::info(void){
    std::cout << "INFO: I cannot believe adding extra "
                 "bacon costs more money. You didn’t put "
                 "enough bacon in my burger! If you did, "
                 "I wouldn’t be asking for more!"
              << std::endl;}
void Harl::warning(void){
    std::cout << "WARNING: I think I deserve to have some extra "
                 " bacon for free. I’ve been coming for years, "
                 "whereas you started working here just last month." 
              << std::endl;}
void Harl::error(void){
    std::cout << "ERROR: This is unacceptable! I want to speak "
                 "to the manager now." 
              << std::endl;}

void Harl::complain(std::string level)
{
    typedef void (Harl::*Membersfunction)(void);
    
    Membersfunction functions[] =
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return ;
        }

    }
}