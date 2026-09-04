/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:06:02 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/04 11:50:03 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not find in container");
    return it;
}

#endif

// std::find(a.begin(), a.end(), val)
// yes iterator pointing to the element value
// no iterator equal to a.end()

// typename T::iterator easyfind(T& container, int value)
// typrname tells the compiler that T::iterator is a type, not a static member
// requires when writing templates that work with containers
// Without typename, the compiler doesn’t know if iterator is a nested type or a member