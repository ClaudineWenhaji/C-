/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:07:13 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/28 12:51:03 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <ctime>
#include <iostream>
#include <cstdlib>

class Base
{
    public:
        virtual ~Base();
};


Base *generate(void);

void identify(Base* p); // prints the actual type of the object pointed to by p: "A", "B" or "C"
                        // p The Base pointer to be checked
void identify(Base& p); // prints the actual type of the object pointed to by p: "A", "B" or "C"
                        // p The Base reference to be checked
#endif

// Identify the real type of an object pointed to by class Base
// this is done dynamically dynamic_cast, with heritage, polymorphism, and RTTI
// RTTI: Runtime Type Information