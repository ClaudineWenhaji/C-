#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Generic Wrong Animal")
{
    std::cout << "WrongAnimal is constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src): type(src.type)
{
    std::cout << "WrongAnimal copy is constructed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
    //std::cout << "WrongAnimal assigment operator" << std::endl;

    if (this != &src)
        type = src.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal is destructed" << std::endl;}

std::string WrongAnimal::getType() const {return type;}