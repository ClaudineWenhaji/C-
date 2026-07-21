/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:10:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/21 11:57:11 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed sign(Point const &p1, Point const &p2, Point const &p3)
{
    // Cross Product Method
    // sign can be neg, pos, or 0 
    // depending on where the point is
    
    return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY())
        -  (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

    Fixed d1 = sign(a, b, point);   // orientation of ab with point
    Fixed d2 = sign(b, c, point);   // orientation of bc with point  
    Fixed d3 = sign(c, a, point);   // orientation of ca with point
   
    if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0)) // on an edge
        return false;
    
    // The 3 orientations should have the same sign
    bool neg_sign = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool pos_sign = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));
    
    return !(neg_sign && pos_sign);
}