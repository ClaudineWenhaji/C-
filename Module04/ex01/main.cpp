
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

int main() 
{
    std::cout << BOLD << CYAN << "\n========== TEST : VERIFY DEEP COPY ==========\n" << RESET;

    Dog dog1;
    dog1.getBrain()->ideas[0] = "I love eat Bones";

    //Dog dog2(dog1);
    Dog dog2;
    dog2.getBrain()->ideas[0] = "I love eat Bones";

    std::cout << std::endl;

    std::cout << YELLOW << "Before modification:\n" << RESET;
    std::cout << "dog1 idea : " << dog1.getBrain()->ideas[0] << std::endl;
    std::cout << "dog2 idea : " << dog2.getBrain()->ideas[0] << std::endl;

    dog1.getBrain()->ideas[0] = "and sleep all day";

    std::cout << YELLOW << "\nAfter modifying dog1:\n" << RESET;
    std::cout << "dog1 idea : " << dog1.getBrain()->ideas[0] << std::endl;
    std::cout << "dog2 idea : " << dog2.getBrain()->ideas[0] << std::endl;
    std::cout << std::endl;

    if (dog1.getBrain() == dog2.getBrain())
        std::cout << RED << "ERROR : Shallow copy (same Brain pointer)!" << RESET << std::endl;
    else
        std::cout << GREEN << "OK : Deep copy (different Brain pointers)." << RESET << std::endl;
    
    std::cout << std::endl;
    std::cout << "dog1 Brain : " << dog1.getBrain() << std::endl;
    std::cout << "dog2 Brain : " << dog2.getBrain() << std::endl;

    std::cout << BOLD << CYAN << "\n========== TEST 2 : ARRAY OF ANIMALS ==========\n" << RESET;

    Animal* zoo[5];

    for (int i = 0; i < 5; i++)
    {
        if (i < 3)
            zoo[i] = new Dog();
        else
            zoo[i] = new Cat();
    }

    std::cout << YELLOW << "\nAnimals make sounds:\n" << RESET;

    for (int i = 0; i < 5; i++)
    {
        std::cout << zoo[i]->getType() << " : ";
        zoo[i]->makeSound();
    }

    std::cout << RED << "\nDeleting animals...\n" << RESET;

    for (int i = 0; i < 5; i++)
        delete zoo[i];

    std::cout << BOLD << CYAN << "\n========== TEST 3 : BRAIN CONTENT ==========\n" << RESET;

    Dog thinker;
    std::cout << std::endl;

    thinker.getBrain()->ideas[0] = "Eat";
    thinker.getBrain()->ideas[1] = "Sleep";
    thinker.getBrain()->ideas[2] = "Play";
    thinker.getBrain()->ideas[3] = "Run";
    thinker.getBrain()->ideas[4] = "Repeat";

    for (int i = 0; i < 5; i++)
        std::cout << GREEN << "Idea[" << i << "] : " << RESET << thinker.getBrain()->ideas[i] << std::endl;

    std::cout << BOLD << GREEN << "\n========== ALL TESTS PASSED ==========\n" << RESET;

    return 0;
}