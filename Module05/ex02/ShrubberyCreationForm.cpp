#include "ShrubberyCreationForm.hpp"
#include <fstream>

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    checkExecutability(executor); // check if form can be executed

    // create output file: target_shrubbery
    std::string filename = Module05 + "_shrubbery";
    std::ofstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("cannot create file");
    
    // write ascii trees to file
    file << "       *" << std::endl;
    file << "      ***" << std::endl;
    file << "     *****" << std::endl;
    file << "    *******" << std::endl;
    file << "   *********" << std::endl;
    file << "  ***********" << std::endl;
    file << "       |" << std::endl;

    file.close();
}