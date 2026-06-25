/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:47:37 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/25 18:57:48 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
Harl::Harl(void){}
Harl::~Harl(void){}

void Harl::debug(void){
    std::cout << "[ DEBUG ]\n I love having extra bacon "
                 "for my 7XL-double-cheese-triple-pickle-special-"
                 "ketchup burger.\n I really do!" 
              << std::endl;}
void Harl::info(void){
    std::cout << "[ INFO ]\n I cannot believe adding extra "
                 "bacon costs more money.\n You didn’t put "
                 "enough bacon in my burger!\n If you did, "
                 "I wouldn’t be asking for more!"
              << std::endl;}
void Harl::warning(void){
    std::cout << "[ WARNING ]\n I think I deserve to have some extra "
                 "bacon for free.\n I’ve been coming for years, "
                 "whereas you started working here just last month." 
              << std::endl;}
void Harl::error(void){
    std::cout << "[ ERROR ]\n This is unacceptable! I want to speak "
                 "to the manager now." 
              << std::endl;}

void Harl::complain(std::string level)
{
    void (Harl::*Memberfunctions[4])() = {&Harl::debug, &Harl::info, 
                                            &Harl::warning, &Harl::error};
    // Array of member function pointers
    
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    int i = 0;
    while (i < 4 && level != levels[i])
        i++;

    switch (i)
    {
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" 
                      << std::endl;
            break;
        case 0:
            (this->*Memberfunctions[0])();
            std::cout << std::endl;
            /*fall through*/
        case 1:
            (this->*Memberfunctions[1])();
            std::cout << std::endl;
            /*fall through*/
        case 2:
            (this->*Memberfunctions[2])();
            std::cout << std::endl;
            /*fall through*/
        case 3:
            (this->*Memberfunctions[3])();
            break;
    }
    
}