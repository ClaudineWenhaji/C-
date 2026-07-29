#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& src);
        WrongAnimal& operator=(const WrongAnimal& src);
        virtual ~WrongAnimal();

        void makeSound(void) const {std::cout << "Some generic sound" << std::endl;};
        
        std::string getType() const;
};

#endif