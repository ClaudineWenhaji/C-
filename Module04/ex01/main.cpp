
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

int main() 
{
    std::cout << BOLD << CYAN
              << "\n========== TEST 1 : POLYMORPHISM ==========\n"
              << RESET;

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << std::endl;
    std::cout << GREEN << dog->getType() << " : " << RESET;
    dog->makeSound();

    std::cout << GREEN << cat->getType() << " : " << RESET;
    cat->makeSound();
    std::cout << std::endl;

    delete dog;
    delete cat;

    std::cout << BOLD << CYAN << "\n========== TEST 2 : DEEP COPY CONSTRUCTOR ==========\n" << RESET;

    Dog original;
    original.getBrain()->ideas[0] = "I love bones";
    std::cout << std::endl;
    Dog copy(original);
    std::cout << std::endl;

    original.getBrain()->ideas[0] = "I hate cats";

    std::cout << GREEN << "Original idea : "
              << RESET << original.getBrain()->ideas[0] << std::endl;

    std::cout << BLUE << "Copy idea     : "
              << RESET << copy.getBrain()->ideas[0] << std::endl;

    std::cout << MAGENTA << "Original Brain : "
              << original.getBrain() << RESET << std::endl;

    std::cout << MAGENTA << "Copy Brain     : "
              << copy.getBrain() << RESET << std::endl;

    std::cout << BOLD << CYAN << "\n========== TEST 3 : ARRAY OF ANIMALS ==========\n" << RESET;

    Animal* zoo[5];

    for (int i = 0; i < 5; i++)
    {
        if (i < 3)
            zoo[i] = new Dog();
        else
            zoo[i] = new Cat();
    }

    std::cout << YELLOW << "\nAnimals make sounds:\n"
              << RESET;

    for (int i = 0; i < 5; i++)
    {
        std::cout << zoo[i]->getType() << " : ";
        zoo[i]->makeSound();
    }

    std::cout << RED << "\nDeleting animals...\n" << RESET;

    for (int i = 0; i < 5; i++)
        delete zoo[i];

    std::cout << BOLD << CYAN
              << "\n========== TEST 4 : BRAIN CONTENT ==========\n"
              << RESET;

    Dog thinker;
    std::cout << std::endl;

    thinker.getBrain()->ideas[0] = "Eat";
    thinker.getBrain()->ideas[1] = "Sleep";
    thinker.getBrain()->ideas[2] = "Play";
    thinker.getBrain()->ideas[3] = "Run";
    thinker.getBrain()->ideas[4] = "Repeat";

    for (int i = 0; i < 5; i++)
        std::cout << GREEN << "Idea[" << i << "] : "
                  << RESET << thinker.getBrain()->ideas[i] << std::endl;

    std::cout << BOLD << GREEN << "\n========== ALL TESTS PASSED ==========\n" << RESET;

    return 0;
}