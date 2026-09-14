/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:50:59 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/14 15:36:54 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {this->dataBase("data.csv");}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {*this = copy;}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
        this->_datafile = src._datafile;
    return *this;
}    
BitcoinExchange::~BitcoinExchange() {}

// --------------------------- PARSING -------------------------- //

void BitcoinExchange::dataBase(const std::string& filename)
{
    // open file (.c_str) for C++98
    std::ifstream file(filename.c_str());
    
    if (!file.is_open())
        throw std::runtime_error("cannot open data file");
        
    std::string line;
    std::getline(file, line); // read a line (buffer to store into) from stream into a string
    
    // Read line by line
    while (std::getline(file, line))
    {
        size_t pos = line.find(","); // find the position of a C string. If not found, return npos
        
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos); // avant la virgule 
            float exchange_rate = std::atof(line.substr(pos + 1).c_str());
            _datafile[date] = exchange_rate;
        }
    }
    
    file.close();
}

// ------------------------- DATE CONSTRAINTS -----------------------------//

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    // date YYYY-MM-DD (10 characters)
    if (date.length() != 10)
        return false;
        
    if (date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
        return false;

    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;
    
    // Number of days in month
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // A year is a leap year if:
    // - Divisible by 4 AND not divisible by 100
    // - OR divisible by 400
    
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeapYear) 
        days[2] = 29;
        
    return day <= days[month]; // retourne true si day <= days[month]
}

// ---------------------------- VALUE CONSTRAINTS ---------------------------//

bool BitcoinExchange::isValidValue(const std::string& value, float& result) const
{
    std::istringstream iss(value); 
    // std::istringstream permet de lire std::string comme si cetait une entree clavier
    // on utilise ensuite >> pour recuperer les valeurs
    
    if (!(iss >> result))
        return false;
    if (result < 0 || result > 1000)
        return false;
    return true;
}

// -------------------- INPUT FILE ------------------------//

void BitcoinExchange::inputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    
    while(std::getline(file, line))
    {
        size_t pos = line.find("|");
        
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);         // du debut jusqu'a |
        std::string valueStr = line.substr(pos + 1);    // apres pos jusqu'a la fin

        while (!date.empty() && date[date.size() - 1] == ' ')
            date.erase(date.size() - 1);
        while (!valueStr.empty() && valueStr[0] == ' ')
            valueStr.erase(0, 1);
            
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        float value;
        if (!isValidValue(valueStr, value))
        {
            if (value < 0)
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            if (value > 1000)
            {
                std::cerr << "Error: too large number." << std::endl;
                continue;
            }
        }
    
        // ----------- find closest date (const std::string& date) const ----------
        
        std::map<std::string, float>::iterator it = _datafile.lower_bound(date);
        // it: is iterator to first element >= date
        
        if (it == _datafile.end() || it->first != date)      // si date est plus grande que toutes les dates it == _datefile.end()
                                                             // ou on a trouve une date qui ne correspond pas exactement a date it->frist != date
        {
            if (it == _datafile.begin())                     // est ce quon est deja au debut?
                                                             // si on est au debut, alors il nya aucun elt au debut, erreur
            {
                std::cerr << "Error: date too early => " << date << std::endl;
                continue;
            }
            --it;       // on veut considerer la date precedente
        }
        
        float exchangeRate = it->second;
        
        std::cout << date << " => " << valueStr << " = " << (exchangeRate * value) << std::endl;
    }
    
    file.close();
}

// ------------------ END ---------------- //

