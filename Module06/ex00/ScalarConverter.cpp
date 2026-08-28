/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:45:24 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/28 16:20:27 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {*this = copy;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) 
{
    (void)src;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

// *************************** PARSING BEGINNING ************************************ //

static bool isChar(const std::string& str)
{
    return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

static bool isInt(const std::string& str) 
{
    if (str.empty())
        return false;

    size_t index = 0;
    if (str[0] == '+' || str[0] == '-')
        index = 1;
        
    if (index == str.size())
        return false;
    
    if (str.find_first_not_of("0123456789", index) != std::string::npos)
        return false;
    return true;
}

static bool isFloat(const std::string& str) 
{
    if (str.empty() || str[str.size() - 1] != 'f')
        return false;

    size_t index = 0;
    
    if (str[0] == '+' || str[0] == '-')
        index = 1;
        
    if (index == str.size())
        return false;

    const size_t dot_pos = str.find('.', index);
    if (dot_pos == std::string::npos)
        return false;
        
    if (str.find('.', dot_pos + 1) != std::string::npos)
        return false;

    const std::string decimalPart = str.substr(index, dot_pos - index); // substr(debut, longueur)
    const std::string fractionalPart = str.substr(dot_pos + 1, str.size() - (dot_pos - 2));
    
    if (decimalPart.empty() || fractionalPart.empty())
        return false;
        
    if (decimalPart.find_first_not_of("0123456789") != std::string::npos 
        || fractionalPart.find_first_not_of("0123456789") != std::string::npos)
        return false;
        
    return true;
}

static bool isDouble(const std::string& str) 
{
    if (str.empty())
        return false;

    size_t index = 0;
    
    if (str[0] == '+' || str[0] == '-')
        index = 1;
        
    if (index == str.size())
        return false;
    
    const size_t dot_pos = str.find('.', index);
    if (dot_pos == std::string::npos)
        return false;
        
    if (str.find('.', dot_pos + 1) != std::string::npos)
        return false;

    const std::string decimalPart = str.substr(index, dot_pos - index); // substr(debut, longueur)
    const std::string fractionalPart = str.substr(dot_pos + 1);
    
    if (decimalPart.empty() || fractionalPart.empty())
        return false;
        
    if (decimalPart.find_first_not_of("0123456789") != std::string::npos 
        || fractionalPart.find_first_not_of("0123456789") != std::string::npos)
        return false;
        
    return true;
}

static bool isPseudoLiteral(const std::string& str)
{
    if (str.empty())
        return false;
        
    if (str == "-inff" || str == "+inff" ||
        str == "-inf" || str == "+inf" ||
        str == "nanf" || str == "nan" ||
        str == "inf" || str == "inff")
        return true;
    return false;
}

// *************************** PARSING END ************************************ //

static void convertToChar(const char &c)
{
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

static void convertToNumber(long double num)
{
    // char
    if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else
        convertToChar(static_cast<char>(num));
        
    // int
    if (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;
        
    // float
    if (num < -std::numeric_limits<float>::max() || num > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    }
    
    // double
    if (num < -std::numeric_limits<double>::max() || num > std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
}

static void convertFromPseudoLiteral(const std::string& str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (str == "nan" || str == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "inf" || str == "inff")
    {
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
    else if (str == "+inf" || str == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inf" || str == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

static void convertFromChar(const std::string str)
{
    convertToChar(str[0]);
    
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isPseudoLiteral(literal))
        convertFromPseudoLiteral(literal);
    else if (isChar(literal))
        convertFromChar(literal);
    else if (isInt(literal))
        convertToNumber(std::strtold(literal.c_str(), NULL));
    else if (isFloat(literal))
        convertToNumber(std::strtold(literal.c_str(), NULL));
    else if (isDouble(literal))
        convertToNumber(std::strtold(literal.c_str(), NULL));
    else
        std::cout << "Unknown type" << std::endl;
}

// Order of detection important: first infinite, then char, int, float, double