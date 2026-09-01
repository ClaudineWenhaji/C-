/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:03:55 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/01 14:42:03 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>

class Array
{
    private:
        T*              _array;
        unsigned int    _size;
    
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& copy);
        Array& operator=(Array const& src);
        ~Array();
        
        T& operator[](unsigned int index);
        unsigned int size() const;
               
        class OutofRange :: public std::exception
        {
            const char* what() const throw();
        };
};

// Inclusion du fichier d'implémentation à la fin
#include "Array.tpp"

// Un fichier .tpp (pour template implementation) 
// contient le code source des fonctions et des classes templates C++ 
// afin de séparer l'implémentation de la déclaration, 
// tout en restant visible par le compilateur

#endif