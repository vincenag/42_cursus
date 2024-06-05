/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:13:47 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/05 10:54:34 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <exception>
# include <ctime>
# include <iomanip>
# include <algorithm>



class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(std::string const & exchangeRate);

        BitcoinExchange(const BitcoinExchange & src);
        ~BitcoinExchange();

        BitcoinExchange & operator=(const BitcoinExchange & rhs);

        void exchange(std::string const & textfile);
        bool isValidDate(const std::string& date);

    private:
        std::map<std::string, float> _exchangeRate;
};

#endif
