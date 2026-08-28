/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 15:28:57 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/28 11:37:36 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib> // strtod, strtof
#include <iostream>
#include <limits>
#include <iomanip> // setprecision

class ScalarConverter
{
    private:
    
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter();
        
    public:
    
        static void convert(const std::string& literal);  
};

#endif