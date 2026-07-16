/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:44:23 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/16 21:52:43 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0))
{
    //std::cout << "Default constructor called" << std::endl;
}

Point::Point(Fixed x, Fixed y): x(x), y(y)
{
    //std::cout << "Constructor called" << std::endl;
}

Point::Point(const Point& src): x(src.x), y(src.y)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point& src)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
    {
        (Fixed) x = src.getX();
        (Fixed) y = src.getY();
    }
    return *this;
}

Point::~Point()
{
    //std::cout << "Destructor called" << std::endl;
}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}

