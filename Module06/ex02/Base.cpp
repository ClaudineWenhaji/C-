/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 17:18:02 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/28 13:23:17 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base::~Base() {};

Base* generate() 
{
    std::srand(time(NULL));
    switch (std::rand() % 3) 
    {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return NULL;
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Cast succeeded: object pointed to A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Cast succeeded: object pointed to B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Cast succeeded; object pointed to C" << std::endl;
    else
        std::cout << "Cast failed. Unknown Type" << std::endl;
}

void identify(Base& p) 
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Cast succeeded: object pointed to &A" << std::endl;
        return;} 
    catch (const std::exception &e) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Cast succeeded: object pointed to &B" << std::endl;
        return;} 
    catch (const std::exception &e) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Cast succeeded: object pointed to &C" << std::endl;
        return;} 
    catch (const std::exception &e) {}
    
    std::cout << "Cast failed: Unknown Reference" << std::endl;
}