/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 16:39:44 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/28 16:45:54 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>

void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T const& min(T const& a, T const& b)
{
    if (a == b)
        return b;
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T const& max(T const& a, T const& b)
{
    if (a == b)
        return b;
    if (a > b)
        return a;
    else 
        return b;
}

#endif