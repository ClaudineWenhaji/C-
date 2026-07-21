/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 20:11:45 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/21 13:59:18 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << std::boolalpha;

    //================ Constructors =================
    std::cout << "===== Constructors =====" << std::endl;

   
    Fixed c(42.42f);
    Fixed d(c);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    //================ Conversions =================
    std::cout << "\n===== Conversions =====" << std::endl;

    std::cout << "b.toInt()   = " << b.toInt() << std::endl;
    std::cout << "c.toFloat() = " << c.toFloat() << std::endl;

    //================ Comparisons =================
    std::cout << "\n===== Comparisons =====" << std::endl;

    Fixed x(5.5f);
    Fixed y(2.25f);

    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    std::cout << "x > y  : " << (x > y) << std::endl;
    std::cout << "x < y  : " << (x < y) << std::endl;
    std::cout << "x >= y : " << (x >= y) << std::endl;
    std::cout << "x <= y : " << (x <= y) << std::endl;
    std::cout << "x == y : " << (x == y) << std::endl;
    std::cout << "x != y : " << (x != y) << std::endl;

    //================ Arithmetic =================
    std::cout << "\n===== Arithmetic =====" << std::endl;

    std::cout << "x + y = " << x + y << std::endl;
    std::cout << "x - y = " << x - y << std::endl;
    std::cout << "x * y = " << x * y << std::endl;
    std::cout << "x / y = " << x / y << std::endl;

    //================ Increment / Decrement =================
    std::cout << "\n===== Increment / Decrement =====" << std::endl;

    Fixed inc;

    std::cout << "inc      = " << inc << std::endl;
    std::cout << "++inc    = " << ++inc << std::endl;
    std::cout << "inc      = " << inc << std::endl;
    std::cout << "inc++    = " << inc++ << std::endl;
    std::cout << "inc      = " << inc << std::endl;
    std::cout << "--inc    = " << --inc << std::endl;
    std::cout << "inc--    = " << inc-- << std::endl;
    std::cout << "inc      = " << inc << std::endl;

    //================ Min / Max =================
    std::cout << "\n===== Min / Max =====" << std::endl;

    Fixed m1(12.5f);
    Fixed m2(7.75f);

    std::cout << "m1 = " << m1 << std::endl;
    std::cout << "m2 = " << m2 << std::endl;

    std::cout << "min = " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max = " << Fixed::max(m1, m2) << std::endl;

    //================ Assignment =================
    std::cout << "\n===== Assignment =====" << std::endl;

    Fixed assign;

    assign = m1;

    std::cout << "assign = " << assign << std::endl;

    return 0;
}
