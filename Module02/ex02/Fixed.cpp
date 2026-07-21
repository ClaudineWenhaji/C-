/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:53:44 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/21 11:02:00 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixedValue(0){}

Fixed::Fixed(const Fixed& src)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed& src)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        fixedValue = src.getRawBits();
    return *this;
}

Fixed::Fixed(const int value_int){
    //std::cout << "Int constructor called" << std::endl;
    fixedValue = value_int << fractionalBits;
}

Fixed::Fixed(const float value_float){
    //std::cout << "Float constructor called" << std::endl;
    fixedValue = (roundf(value_float * (1 << fractionalBits)));
}

Fixed::~Fixed(){}

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
}


//------------------ Comparison Operators----------------------------------

bool Fixed::operator>(const Fixed& src) const
{
    return fixedValue > src.fixedValue;
}

bool Fixed::operator<(const Fixed& src) const
{
    return fixedValue < src.fixedValue;
}

bool Fixed::operator<=(const Fixed& src) const
{
    return fixedValue <= src.fixedValue;
}

bool Fixed::operator>=(const Fixed& src) const
{
    return fixedValue >= src.fixedValue;
}

bool Fixed::operator==(const Fixed& src) const
{
    return fixedValue == src.fixedValue;
}

bool Fixed::operator!=(const Fixed& src) const
{
    return fixedValue != src.fixedValue;
}

//---------------------- Arithmetic operators--------------------------------

Fixed Fixed::operator+(const Fixed& src) const
{
    return Fixed(toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed& src) const
{
    return Fixed(toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed& src) const
{
    return Fixed(toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed& src) const
{
    return Fixed(toFloat() / src.toFloat());
}

//--------------------- Increment / Decrement ---------------------------

// PRE increment / decrement ++a --a
Fixed& Fixed::operator++()
{
    fixedValue++;
    return *this; // return reference
}

Fixed& Fixed::operator--()
{
    fixedValue--;
    return *this;
}

// POST increment / decrement a++ a--
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this); // Save current value
    fixedValue++;     // increment
    return tmp;       // return old value
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this); // Save current value
    fixedValue--;     // increment
    return tmp;       // return old value
}

//----------------------------- Min / Max -----------------------------------------

Fixed& Fixed::min(Fixed& fixed_a, Fixed& fixed_b)
{
    return (fixed_a < fixed_b) ? fixed_a : fixed_b;
}

const Fixed& Fixed::min(const Fixed& fixed_a, const Fixed& fixed_b)
{
    return (fixed_a < fixed_b) ? fixed_a : fixed_b;
}

Fixed& Fixed::max(Fixed& fixed_a, Fixed& fixed_b)
{
    return (fixed_a > fixed_b) ? fixed_a : fixed_b;
}

const Fixed& Fixed::max(const Fixed& fixed_a, const Fixed& fixed_b)
{
    return (fixed_a > fixed_b) ? fixed_a : fixed_b;
}

// Must be non-member function (ostream is on the left)
std::ostream& operator<<(std::ostream& os, const Fixed& right) {
    os << right.toFloat();
    return os;
}