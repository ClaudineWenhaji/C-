/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:11:32 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/08 11:14:09 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

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