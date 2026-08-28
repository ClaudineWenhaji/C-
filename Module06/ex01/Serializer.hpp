/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:29:34 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/28 13:04:46 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& copy);
        Serializer& operator=(const Serializer& src);
        ~Serializer();
        
    public:
        static uintptr_t serialize(Data* ptr); // transform a pointer address to an integer address
        static Data* deserialize(uintptr_t raw);
};

#endif

// Understand how to convert a pointer to and integer
// and vice-versa
// A memory address can be represented as an integer
// and then reconverted into a pointer
// uintptr_t integer type capable to contain an address