/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 19:19:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/17 20:04:04 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

std::string search_and_replace(const std::string& content,
                                const std::string& s1,
                                const std::string& s2)
{
    if (s1.empty())
        return content;
    
}

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string filename = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
        
        std::ifstream inFile(filename.c_str());
        if (!inFile.is_open())
        {
            std::cerr << "Cannot open file" << std::endl;
            return (1);
        }

        std::string content;
        std::string line;

        while (std::getline(inFile, line))
        {
            if (content == "\n")
                return (1);
            else 
            {
                content += line;
                content += "\n";
            }

        }
        inFile.close();

        std::string outFilename = filename + ".replace";
        std::ofstream outFile(outFilename.c_str());
        if(!outFile.is_open())
        {
            std::cerr << "Cannot create output file" << std::endl;
            inFile.close();
            return (1);
        }
        
        
        std::string result = search_and_replace(content, av[2], av[3]);
        outFile << result;
        outFile.close();
        
    }
    return (0);
}