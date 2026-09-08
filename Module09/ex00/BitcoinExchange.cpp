/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:50:59 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/07 18:06:22 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() 
{
    this->dataFile("data.csv");
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
    *this = copy;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
        this->_datafile = src._datafile;
    return *this;
}
    
BitcoinExchange::~BitcoinExchange() {}

// --------------------------- PARSING -------------------------- //

void BitcoinExchange::dataFile(const std::string& filename)
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
        size_t pos = line.find(",");
        
        if (pos != std::string::npos)
        {
            std::string date = line.substr(0, pos); // avant la virgule 
            float rate = std::atof(line.substr(pos + 1).c_str());
            _datafile[date] = rate;
        }
    }
    
    file.close();
}

// -------------------- INPUT FILE ------------------------//

void BitcoinExchange::processInput(const std::string& filename)
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
        std::string date = line.substr(0, pos); // du debut jusqu'a |
        std::string valueStr = line.substr(pos + 1); // apres pos jusqu'a la fin
        // trim enleve les espaces.

        while (!date.empty() && date[date.size() -1] == ' ')
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
        
        if (it == _datafile.end() || it->first != date)
        {
            if (it == _datafile.begin())
            {
                std::cerr << "Error: date too early => " << date << std::endl;
                continue;
            }
            --it;
        }
        
        float rate = it->second;
        std::cout << date << " => " << valueStr << " = " << (rate * value) << std::endl;
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

// ------------------ END ---------------- //

