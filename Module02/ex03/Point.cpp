/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:44:23 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/21 11:20:08 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0)){}

Point::Point(const float x, const float y): x(x), y(y){}

Point::Point(const Point& src): x(src.x), y(src.y){}

Point &Point::operator=(const Point& src)
{
    if (this != &src)
    {
        // Nothing to do because x and y are const
    }
    return *this;
}

Point::~Point(){}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}

