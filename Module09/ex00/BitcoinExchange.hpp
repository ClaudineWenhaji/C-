/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:40:17 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/09/14 15:31:30 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _datafile; // map<keytype, valuetype> mapName

        bool isValidDate(const std::string& date) const;
        bool isValidValue(const std::string& value, float& result) const;
        
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& src);
        ~BitcoinExchange();

        void dataBase(const std::string& filename);
        void inputFile(const std::string& filename);
    
};

#endif