#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat is constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal(src)
{
    this->type = src.type;
    std::cout << "WrongCat copy is constructed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
    if (this != &src)
        type = src.type;
    return *this;
}

WrongCat::~WrongCat(){std::cout << "WrongCat is destructed" << std::endl;}