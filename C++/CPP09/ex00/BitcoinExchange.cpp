/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:30:11 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/12 19:45:38 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(std::string const & exchangeRate) {
    std::ifstream file(exchangeRate.c_str());

    if (!file.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }
        
        std::istringstream iss(line); // crea un objeto iss del tipo std::istringstream y lo inicializa con el contenido de line
        std::string date;
        std::string rate;
        float value;

        if (std::getline(iss, date, ',') && std::getline(iss, rate)) {
            try{
                value = atof(rate.c_str());
            }
            catch (std::invalid_argument & e) {
                std::cerr << "Error: invalid argument" << std::endl;
                return;
            }
            _exchangeRate[date] = value;
        }
    }

    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src) {
    *this = src;
}

BitcoinExchange::~BitcoinExchange() {

}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & rhs) {
    if (this != &rhs) {
        _exchangeRate = rhs._exchangeRate;
    }
    return *this;
}

bool BitcoinExchange::isnumber(const std::string &s) {
    for (size_t i = 0; i < s.length(); i++) {
        if ((s[i] == '-' && i == 0) || s[i] == '.')
            continue;
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    std::istringstream ss(date);
    int day, month, year;

    // Parse the date string
    size_t dash = date.find('-');
    if (dash == std::string::npos || !isnumber(date.substr(0, dash)) || date.substr(0, dash).length() != 4)
        return false;

    year = std::atoi(date.substr(0, dash).c_str());
    size_t dash2 = date.find('-', dash + 1);

    if (dash2 == std::string::npos || !isnumber(date.substr(dash + 1, dash2 - dash - 1)) || date.substr(dash + 1, dash2 - dash - 1).length() != 2)
        return false;
    month = std::atoi(date.substr(dash + 1, dash2 - dash - 1).c_str());

    if (!isnumber(date.substr(dash2 + 1)) || date.substr(dash2 + 1).length() != 2)
        return false;
    day = std::atoi(date.substr(dash2 + 1).c_str());

  
    // Check if the year is a leap year
    bool isLeapYear = (year % 4 == 0 && year % 100!= 0) || (year % 400 == 0);

    // Days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust days in February for leap years
    if (isLeapYear)
        daysInMonth[1] = 29;

    // Validate day and month
    if (day > 0 && day <= daysInMonth[month - 1])
        return true;
    else 
        return false;
}


void BitcoinExchange::exchange(std::string const & textfile) {
    std::ifstream inputFile(textfile.c_str());

    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(inputFile, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }

        std::istringstream iss(line);
        std::string date;
        std::string amount;
        float value;

        size_t pipe = line.find('|');
        if (pipe != std::string::npos) {
            date = line.substr(0, pipe);
            amount = line.substr(pipe + 1);
            date.erase(date.find_last_not_of(" \n\r\t") + 1); // Eliminar espacios al final de la fecha
            amount.erase(0, amount.find_first_not_of(" \n\r\t")); // Eliminar espacios al inicio del monto
        } else {
            date = line;
            date.erase(date.find_last_not_of(" \n\r\t") + 1); // Eliminar espacios al final de la fecha
            amount = "";
        }

        try {
            if (!isValidDate(date)) {
                throw std::invalid_argument("Error: bad input => " + date);
            }

            if (!amount.empty()) {
                if (!isnumber(amount)) {
                    throw std::invalid_argument("Error: amount is not a number => " + amount);
                }
                value = std::atof(amount.c_str());
                if (value < 0) {
                    throw std::invalid_argument("Error: not a positive number");
                } else if (value > 1000) {
                    throw std::invalid_argument("Error: too large a number");
                }
            } else {
                throw std::invalid_argument("Error: missing amount for date => " + date);
            }
        } catch (const std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _exchangeRate.lower_bound(date);
        

        // Si no hay coincidencia exacta, buscar la fecha pasada más cercana
        if (it == _exchangeRate.end() || it->first != date) {
            if (it != _exchangeRate.begin()) {
                --it;
            } else {
                std::cerr << "Error: no exchange rate found for or before " << date << std::endl;
                continue;
            }
        }

        float result = value * it->second;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    inputFile.close();
}


