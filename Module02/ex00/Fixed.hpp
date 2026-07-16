/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:43:34 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/16 15:19:46 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
  
private:
    int fixedValue;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed& src);
    Fixed& operator=(const Fixed& src);
    ~Fixed();  
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif 