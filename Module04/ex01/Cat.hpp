#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* catBrain;

    public:
        Cat();
        Cat(const Cat& src);
        Cat& operator=(const Cat& src);
        ~Cat();

        void makeSound() const{std::cout << "Meow! Meow!" << std::endl;};
        Brain* getBrain() const;
};

#endif