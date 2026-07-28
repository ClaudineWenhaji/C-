#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal& src);
        Animal& operator=(const Animal& src);
        virtual ~Animal();

        virtual void makeSound(void) const {std::cout << "Some generic sound" << std::endl;};
        
        std::string getType() const;
};

#endif