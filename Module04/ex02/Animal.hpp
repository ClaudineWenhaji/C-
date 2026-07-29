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

        virtual void makeSound(void) const = 0; // pure virtual function
        // cannot create instances of abstract class
        // CAN have pointers/references to abstract class
        // Derived classes MUST implement pure virtual functions
        
        std::string getType() const;
};

#endif