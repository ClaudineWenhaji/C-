/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:40:17 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/07 17:44:55 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _datafile;

        bool isValidDate(const std::string& date) const;
        bool isValidValue(const std::string& value, float& result) const;
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

        void dataFile(const std::string& filename);
        void processInput(const std::string& filename);
    
};

#endif