#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
    protected:
        std::string type;

    public:
        AAnimal();
        AAnimal(const AAnimal& src);
        AAnimal& operator=(const AAnimal& src);
        virtual ~AAnimal();

        virtual void makeSound(void) const = 0; // pure virtual function
        // cannot create instances of abstract class
        // CAN have pointers/references to abstract class
        // Derived classes MUST implement pure virtual functions
        
        std::string getType() const;
};

#endif