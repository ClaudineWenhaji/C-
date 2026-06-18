/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 19:19:50 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/18 14:40:21 by clwenhaj         ###   ########.fr       */
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
    std::string result;
    std::size_t pos = 0;
    std::size_t found;
    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(content, pos, std::string::npos);
    return result;
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0]
              << " <filename> <s1> <s2>" << std::endl;
        return (1);
    }
  
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
        
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open())
    {
        std::cerr << "Error: Cannot open file" << filename << std::endl;
        return 1;
    }

        /*std::string content;
        std::string line;
        while (std::getline(inFile, line))
        {
            content += line;
            content += "\n";
        }*/

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    std::string content = buffer.str();
        
    inFile.close();

    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if(!outFile.is_open())
    {
        std::cerr << "Cannot create output file" << std::endl;
           return 1;
    }
        
    std::string result = search_and_replace(content, s1, s2);
    outFile << result;
    outFile.close(); 
    return 0;
}