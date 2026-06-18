/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:47:41 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/06/18 15:21:19 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
public:
    Harl(void);
    ~Harl(void);
    void complain(std::string level);
};

#endif