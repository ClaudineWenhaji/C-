/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:43:34 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/16 19:21:13 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed{
  
private:
    int fixedValue;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed& src);
    Fixed(const int value_int);
    Fixed(const float value_float);
    ~Fixed(); 
    
    Fixed& operator=(const Fixed& src);
   
    // Comparison
    bool operator>(const Fixed& src) const;
    bool operator<(const Fixed& src) const;
    bool operator>=(const Fixed& src) const;
    bool operator<=(const Fixed& src) const;
    bool operator==(const Fixed& src) const;
    bool operator!=(const Fixed& src) const;
     
    // Arithmetic
    Fixed operator*(const Fixed& src) const;
    Fixed operator/(const Fixed& src) const;
    Fixed operator+(const Fixed& src) const;
    Fixed operator-(const Fixed& src) const;
    
    // Static min/max
    static Fixed& min(Fixed& fixed_a, Fixed& fixed_b);
    static const Fixed& min(const Fixed& fixed_a, const Fixed& fixed_b);
    static Fixed& max(Fixed& fixed_a, Fixed& fixed_b);
    static const Fixed& max(const Fixed& fixed_a, const Fixed& fixed_b);

    //  Increment/Decrement
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    
    float toFloat( void ) const;
    int toInt( void ) const;
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& right);

#endif 