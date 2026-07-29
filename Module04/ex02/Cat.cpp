#include "Cat.hpp"

Cat::Cat(): Animal()
{
    this->type = "Cat";
    this->catBrain = new Brain;
    std::cout << "Cat is constructed" << std::endl;
}

Cat::Cat(const Cat& src): Animal(src)
{
    this->catBrain = new Brain(*src.catBrain);
    std::cout << "Cat DEEP copy is constructed" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
    if (this != &src)
        delete catBrain;
        catBrain = new Brain(*src.catBrain);
    return *this;
}

Cat::~Cat()
{
    delete catBrain;
    std::cout << "Cat is destructed" << std::endl;
}

Brain* Cat::getBrain() const{return catBrain;}