/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:43:34 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/21 10:36:33 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{ 
    private:
        int fixedValue;
        static const int fractionalBits = 8;
        
    public:
        Fixed();
        Fixed(const Fixed& src);
        Fixed& operator=(const Fixed& src);
        ~Fixed();
                 
        Fixed(const int value_int);
        Fixed(const float value_float);
    
        float toFloat( void ) const;
        int toInt( void ) const;
    
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif 