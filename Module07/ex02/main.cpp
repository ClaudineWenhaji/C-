#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include "Colors.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    // "Array Creation" 

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(time(NULL));

    // "Fill in the Array" 
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // "Copy Test" 
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    //"Values Verification" 
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout << std::endl;
    std::cout << GREEN << "Test1: negative index" << RESET << std::endl;

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
    std::cout << GREEN << "Test2: Too High Index" << RESET << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;
    std::cout << GREEN << "Test3 Valid indices" << RESET << std::endl;

    try 
    {
        const int size = 10;

        Array<int> obj(size);
        for (int i = 0; i < size; i++)
        {
            obj[i] = i;
            std::cout << "Index " << i << " = " << obj[i] << std::endl;
        }

        std::cout << std::endl;

        Array<int> obj2(obj);

        for (int i = 0; i < size; i++) 
        {
            std::cout << "Index " << i << " = " << obj[i] << std::endl;
        }
    } 
    catch (const std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try 
    {
        Array<int> obj;
        obj[0] = 5;
        std::cout << obj[0] << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    try 
    {
        char letter = 'a';
        Array<char> obj(10);
        for (int i = 0; i <= 10; i++) 
        {
            obj[i] = letter++;
            std::cout << "Index " << i << " = " << obj[i] << std::endl;
        }

        obj[8] = 'a';
        std::cout << obj[8] << std::endl;
        std::cout << "Size of the object is " << obj.size() << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }

    delete [] mirror;//

    return 0;
}