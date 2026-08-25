/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 16:45:24 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/25 16:59:11 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>

static bool isChar(const std::string& str)
{
    return (str.length() == 1 && !isdigit(str[0]));
}

static bool isInt(const std::string& str) {}

static bool isFloat(const std::string& str) {}

static bool isDouble(const std::string& str) {}


void ScalarConverter::convert(const std::string& literal)
{
    
}