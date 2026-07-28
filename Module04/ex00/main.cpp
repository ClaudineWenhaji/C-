
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

int main() 
{
    std::cout << std::endl << GREEN << "----------- Constructors ------------" << RESET << std::endl;
    std::cout << std::endl;

    // Test polymorphism
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << std::endl << GREEN << "----------- RESULTS ------------" << RESET << std::endl;
    std::cout << std::endl;

    std::cout << BLUE << animal->getType() << ": " << RESET;
    animal->makeSound();  // "Generic animal sound" 

    std::cout << std::endl;
    std::cout << RED << dog->getType() << ": " << RESET;
    dog->makeSound();     // "Woof!"

    std::cout << std::endl;
    std::cout << YELLOW << cat->getType() << ": " << RESET;
    cat->makeSound();     // "Meow!"

    std::cout << std::endl << GREEN << "------------ Destructors ----------" << RESET << std::endl;
    std::cout << std::endl;

    delete animal;
    delete dog;
    delete cat;

    // Compare with WrongAnimal
    std::cout << GREEN << "\n--------- Wrong versions ---------\n" << RESET;
    std::cout << std::endl;

    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << std::endl;
    std::cout << YELLOW << wrongCat->getType() << ": " << RESET;
    wrongCat->makeSound();  // Calls WrongAnimal::makeSound(), NOT WrongCat!
    std::cout << std::endl;
    delete wrongCat;
    std::cout << std::endl;

    return 0;
}