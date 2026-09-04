/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 18:16:18 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/04 16:14:01 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "Colors.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << std::endl;
    std::cout << GREEN << "----------------- Test1: Basic MutantStack vs List ------------------" << RESET << std::endl;
    std::cout << std::endl;
    
 //-----------------------------------------------------------------   
 
    std::cout << YELLOW << "MutantStack " << RESET << std::endl; 
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.pop();
    std::cout << "Empty ? " << mstack.empty() << std::endl;
    std::cout << "New Top: " << mstack.top() << std::endl;
    std::cout << "New Size: " << mstack.size() << std::endl;
 
//-----------------------------------------------------------------
    std::cout << std::endl;
    std::cout << YELLOW << "LIST" << RESET << std::endl; 

    std::list<int> lst;
    
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "Back std::list: " << lst.back() << std::endl;
    std::cout << "Size: " << lst.size() << std::endl;
    
    lst.pop_back();
    std::cout << "Empty ? " << lst.empty() << std::endl;
    std::cout << "New Back std::list: " << lst.back() << std::endl;
    std::cout << "New Size: " << lst.size() << std::endl;

//--------------------------------------------------------------------    
    
    std::cout << std::endl;
    std::cout << GREEN << "----------------- Test2: Iterations MutantStack vs List ------------------" << RESET << std::endl;
    std::cout << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator itr = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++itr;
    --itr;
    
    std::cout << std::endl;
    std::cout << BLUE << "Forward MutantStack: " << RESET << std::endl;
    while (itr != ite)
    {
        std::cout << *itr << std::endl;
        ++itr;
    }

//-----------------------------------------------------------------

    // LIST 

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ie = lst.end();
    
    ++it;
    --it;
    
    std::cout << std::endl;
    std::cout << BLUE << "Forward List: " << RESET << std::endl;
    while (it != ie)
    {
        std::cout << *it << std::endl;
        ++it;
    }

//-----------------------------------------------------------------
    
    std::cout << std::endl;
    std::cout << GREEN << "----------------- Test 3: Reverse iterator ----------------" << RESET << std::endl;
    std::cout << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator ren = mstack.rend();

    std::cout << BLUE << "Reverse: "<< RESET << std::endl;

    while (rit != ren)
    {
        std::cout << *rit << " " << std::endl;
        ++rit;
    }

    //----------------------------------
    
    std::cout << std::endl;
    std::cout << GREEN << "----------------- Test 4: Const iterator ----------------"
              << RESET << std::endl;
    std::cout << std::endl;

    const MutantStack<int> constStack(mstack);

    MutantStack<int>::const_iterator constIt = constStack.begin();
    MutantStack<int>::const_iterator constIte = constStack.end();

    std::cout << BLUE << "Const: " << RESET << std::endl;

    while (constIt != constIte)
    {
        std::cout << *constIt << " " << std::endl;
        ++constIt;
    }
    std::cout << std::endl;
    
    return 0;
    //std::stack<int> s(mstack); // crée une nouvelle std::stack<int> en copiant ton MutantStack<int>
}