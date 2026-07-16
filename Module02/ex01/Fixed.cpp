/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:53:44 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/16 17:26:52 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixedValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed& src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        fixedValue = src.getRawBits();
    return *this;
}

Fixed::Fixed(const int value_int){
    std::cout << "Int constructor called" << std::endl;
    fixedValue = value_int << fractionalBits;
}

Fixed::Fixed(const float value_float){
    std::cout << "Float constructor called" << std::endl;
    fixedValue = (roundf(value_float * (1 << fractionalBits)));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return fixedValue;
}

void Fixed::setRawBits( int const raw )
{
    fixedValue = raw;
}

int Fixed::toInt() const{
    return fixedValue >> fractionalBits;
}

float Fixed::toFloat() const{
    return (float)fixedValue / (1 << fractionalBits);
    // cast first to float. Integer division gives 0 for small value
}

// Must be non-member function (ostream is on the left)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}