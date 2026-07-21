/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:50:26 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/21 11:32:51 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    Point inside(5, 5);
    Point outside(15, 5);
    Point edge(5, 0);
    Point vertex(0, 0);

    std::cout << std::boolalpha;

    std::cout << "Inside  : " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside : " << bsp(a, b, c, outside) << std::endl;
    std::cout << "On edge : " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Vertex  : " << bsp(a, b, c, vertex) << std::endl;

// -------------------------------------------------------------------
    
    Point p1(5, 9);
    Point p2(-1, 1);
    Point p3(6, 1);

    std::cout << "Near top    : " << bsp(a, b, c, p1) << std::endl;
    std::cout << "Left side   : " << bsp(a, b, c, p2) << std::endl;
    std::cout << "Right side  : " << bsp(a, b, c, p3) << std::endl;

    return 0;
}