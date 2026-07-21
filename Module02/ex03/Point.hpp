/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:34:53 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/07/21 11:18:02 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& src);
        Point& operator=(const Point& src);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
    
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
