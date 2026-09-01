/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:19:12 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/01 14:42:57 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T> Array<T>::Array(): _array(NULL), _size(0) {}

template <class T> Array<T>::Array(unsigned int n): _array(new T[n]()),  _size (n) 
{
    std::cout << "[Array] is constructed" << std::endl;
    this->_array = new T[n];
}

template <class T> Array<T>::Array(const Array& copy)
{
    this->_array = new T[copy.size()];
    
    for (unsigned int i = 0; i < copy.size(); i++)
        this->_array[i] = copy._array[i];
    this->_size = copy._size;
}

template <class T> Array<T>& Array<T>::operator=(Array const& src)
{
    if (this == &src)
        return *this;
    delete[] this->_array;
    
    this->_array = new T[src.size()];

    for (unsigned int i = 0; i < src.size(); i++)
        this->_array[i] = src._array[i];
    this->_size = src._size;

    return *this;
}

template <class T> Array<T>::~Array()
{
    delete[] this->_array;
    std::cout << "[Array] is destructed" << std::endl;
}

template <class T> unsigned int Array<T>::size() const
{
    return _size;
}

template <class T> T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->size())
        throw OutofRange();
    return this->_array[index];
}

template <class T> const char *Array<T>::OutofRange::what() const throw()
{
    return "Index is out of range";
}
