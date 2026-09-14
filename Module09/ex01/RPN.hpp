/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:11:32 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/14 13:24:24 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>

class RPN
{
    private:
        std::stack<int> _stack;

    public:
        RPN();
        RPN(const RPN& copy);
        RPN& operator=(const RPN& src);
        ~RPN();

        int evaluate(const std::string& expression);
};

#endif