/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:19:12 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/02 12:04:37 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T> Array<T>::Array(): _array(NULL), _size(0) {}

template <class T> Array<T>::Array(unsigned int n): _array(new T[n]()),  _size (n) {}

template <class T> Array<T>::Array(const Array& copy) : _array(NULL), _size(0)
{
    *this = copy;
}

template <class T> Array<T>& Array<T>::operator=(Array const& src)
{
    if (this != &src)
    {
        T* new_array = new T[src._size];
        
        for (unsigned int i = 0; i < src.size(); i++)
            new_array[i] = src._array[i];
        
        delete[] this->_array;
        _array = new_array;
        _size = src._size;
    }
    return *this;
}

template <class T> Array<T>::~Array()
{
    delete[] this->_array;
}

template <class T> unsigned int Array<T>::size() const
{
    return _size;
}

template <class T> T& Array<T>::operator[](unsigned int index)
{
    if (index >= this->size())
        throw std::out_of_range("Index is out of bounds");
    return this->_array[index];
}
