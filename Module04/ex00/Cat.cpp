#include "Cat.hpp"

Cat::Cat(): Animal()
{
    this->type = "Cat";
    std::cout << "Cat is constructed" << std::endl;
}

Cat::Cat(const Cat& src): Animal(src)
{
    this->type = src.type;
    std::cout << "Cat copy is constructed" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
    if (this != &src)
        type = src.type;
    return *this;
}

Cat::~Cat(){std::cout << "Cat is destructed" << std::endl;}