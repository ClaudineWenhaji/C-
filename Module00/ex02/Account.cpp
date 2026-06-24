/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:21:04 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/24 15:53:22 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// Initialiser les variables statiques
int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Constructeur
Account::Account(int initial_deposit)
{
    Account::_displayTimestamp();
    
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    
    Account::_nbAccounts++;
    Account::_totalAmount = Account::_totalAmount + this->_amount;
    
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;
}

// Destructeur
Account::~Account()
{
    Account::_displayTimestamp();
    
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl; 
}

void    Account::_displayTimestamp(void)
{
    char buf[20];
    
    std::time_t curr_time = std::time(NULL);
    std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", std::localtime(&curr_time));
    std::cout << buf;
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    
    std::cout << " accounts:" << Account::getNbAccounts()
              << ";total:" << Account::getTotalAmount()
              << ";deposits:" << Account::getNbDeposits()
              << ";withdrawals:" << Account::getNbWithdrawals()
              << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";deposit:" << deposit;
            
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;

    std::cout << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << this->_amount;
    
    if (withdrawal > this->_amount)
    {
        std::cout << ";withdrawal:refused" 
                  << std::endl;
        return false;
    }
    else
    {
        std::cout << ";withdrawal:" << withdrawal;
        
        this->_amount = this->_amount - withdrawal;
        this->_nbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        
        std::cout << ";amount:" << this->_amount
                  << ";nb_withdrawals:" << this->_nbWithdrawals
                  << std::endl;
        
        return true;
    }
        
}

int		Account::checkAmount( void ) const
{
    return this->_amount;
}

// GETTERS
int	Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

int	Account::getNbAccounts( void )
{
    return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

