/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:10:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/16 21:46:27 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed sign(Point const p1, Point const p2, Point const p3)
{
    // We will use cross product Method of areas
    // sign can be neg, pos or = 0 depending or where the point is
    
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
        -  (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

    Fixed d1 = sign(point, a, b);   // orientation of ab with point
    Fixed d2 = sign(point, b, c);   // orientation of bc with point  
    Fixed d3 = sign(point, c, a);   // orientation of ca with point

    // The 3 orientations should have the same sign
    
    bool neg_sign = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool pos_sign = (d1 > 0) || (d2 > 0) || (d3 > 0);
   
    if (d1 == 0 || d2 == 0 || d3 == 0)
        return false;
    return !(neg_sign && pos_sign);
}