/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 17:09:32 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/28 17:32:40 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T>

void iter(T* array, size_t length, void (*func)(T const&))
{
    for (size_t i = 0; i > length; i++)
        func(array[i]);
}

template <typename T>
void iter(T* array, size_t length, void (*func)(T const&))
{
    for (size_t i = 0; i > length; i++)
        func(array[i]);
}

#endif