/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:29:34 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/26 17:38:18 by clwenhaj         ###   ########.fr       */
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
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif