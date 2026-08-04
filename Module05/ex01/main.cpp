#include "Bureaucrat.hpp"
#include "Colors.hpp"

int main()
{
    std::cout << GREEN << "********* TEST1  ***********" << RESET << std::endl;

    try
    {
        Bureaucrat A("Claudine", 0);

        A.incrementGrade();
        std::cout << GREEN << "After increment: " << YELLOW << A << RESET << RESET << std::endl;

        A.decrementGrade();
        std::cout << GREEN << "After decrement: " << YELLOW << A << RESET << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << GREEN << "********* TEST2  ***********" << RESET << std::endl;
    
    try
    {
        Bureaucrat invalid("Claudine", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " <<  e.what() << RESET << '\n';
    }
    
    std::cout << GREEN << "********* TEST3  ***********" << RESET << std::endl;
    try
    {
        Bureaucrat out("Claudine", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Exception: " <<  e.what() << RESET << '\n';
    }
    

    return 0;
}