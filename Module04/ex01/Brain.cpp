#include "Brain.hpp"
#include <iostream>

Brain::Brain(){std::cout << "Brain is constructed" << std::endl;}

Brain::Brain(const Brain& src)
{
    std::cout << "Brain copy is constructed" << std::endl;
    
    for (int i = 0; i < 100; i++)
        ideas[i] = src.ideas[i];
}

Brain& Brain::operator=(const Brain& src)
{
    if (this != &src)
        for (int i = 0; i < 100; i++)
            ideas[i] = src.ideas[i];
    return *this;
}

Brain::~Brain(){std::cout << "Brain is destructed" << std::endl;}
