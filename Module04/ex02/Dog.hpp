#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal{

    private:
        Brain* dogBrain; // dynamic allocation

    public:

        Dog();
        Dog(const Dog &src);
        Dog& operator=(const Dog& src);
        ~Dog();

        virtual void makeSound()const {std::cout << "Woof! Woof!" << std::endl;};
        Brain* getBrain() const;
};

#endif