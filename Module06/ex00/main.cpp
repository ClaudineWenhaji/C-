/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:57:57 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/08/26 15:59:02 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char* av[])
{
    if (ac != 2) {
        std::cout << "Error: Argument Error!" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}