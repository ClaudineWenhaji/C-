/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 11:29:10 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/04 16:03:36 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{        
    public:

        MutantStack();
        MutantStack(const MutantStack& copy); 
        MutantStack& operator=(MutantStack const& src);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin();
        iterator end();
        
        const_iterator begin() const;
        const_iterator end() const;
        
        reverse_iterator rbegin();
        reverse_iterator rend();
        
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
};


// ---------- Implementation Canonical Form ----------//

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& src)
{
    std::stack<T>::operator=(src);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

// -------- Implementation of Iterator methods of STACK Container ---------//

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() 
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return this->c.rend();
}

#endif

// include <stack>: stack has NO iterator by default LIFO (Last In, First Out)
// typedef typename std::stack<T>::container_type::iterator iterator;

// std::stack is a container adapter that wraps another container
// std::stack has a protected member c (the underlying container)

// As a derived class, MutantStack can access this->c
// The iterator types are exposed using container_type::iterator
// The typename keyword is required because the type depends on template parameter T
// Without typename, compiler might think container_type::iterator is a value