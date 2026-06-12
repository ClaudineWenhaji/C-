/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:21:04 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/12 11:35:10 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    Account::_displayTimestamp();
    
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_nbAccounts++;
    Account::_totalAmount = Account::_totalAmount + this->_amount;
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl; 
}

void	makeDeposit( int deposit )
{
    //Account::_displayTimestamp();
    this->_amount = this->_amount + deposit;
    this->_nbDeposits = _nbDeposits + 1;
    Account::_totalNbDeposits++;
}

static void	displayAccountsInfos( void )
{
    
}


bool	makeWithdrawal( int withdrawal )
{
    if (withdrawal > this->_amount)
    {
        std::cout << "You do not have enough money. Choose another amount" << std::endl;
        return false;
    }
    else
    {
        this->_amount = this->_amount - withdrawal;
        this->_nbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        return true;
    }
        
}

int		checkAmount( void )
{
    
}

void	displayStatus( void )
{
    
}

static int	getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

static int	getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

static int	getNbAccounts( void )
{
    return Account::_nbAccounts;
}

static int	getTotalAmount( void )
{
    return Account::_totalAmount;
}

