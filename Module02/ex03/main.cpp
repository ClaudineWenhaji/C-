/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:50:26 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/16 21:54:06 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(10), Fixed(0));
    Point c(Fixed(5), Fixed(10));

    Point inside(Fixed(5), Fixed(5));
    Point outside(Fixed(15), Fixed(5));
    Point edge(Fixed(5), Fixed(0));
    Point vertex(Fixed(0), Fixed(0));

    std::cout << std::boolalpha;

    std::cout << "Inside  : " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside : " << bsp(a, b, c, outside) << std::endl;
    std::cout << "On edge : " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Vertex  : " << bsp(a, b, c, vertex) << std::endl;

// -------------------------------------------------------------------
    
    Point p1(Fixed(5), Fixed(9));
    Point p2(Fixed(-1), Fixed(1));
    Point p3(Fixed(6), Fixed(1));

    std::cout << "Near top    : " << bsp(a, b, c, p1) << std::endl;
    std::cout << "Left side   : " << bsp(a, b, c, p2) << std::endl;
    std::cout << "Right side  : " << bsp(a, b, c, p3) << std::endl;

    return 0;
}