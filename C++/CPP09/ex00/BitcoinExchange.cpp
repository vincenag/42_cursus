/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:30:11 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/31 10:19:06 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(std::string const & exchangeRate) {
    std::ifstream file(exchangeRate);

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
                value = std::stod(rate);
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

bool isValidDate(const std::string& date) {
    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        return false;
    }
    std::ostringstream os;
    os << std::put_time(&tm, "%Y-%m-%d");
    return os.str() == date;
}

void BitcoinExchange::exchange(std::string const & textfile) {
    std::ifstream inputFile(textfile);

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
                value = std::stof(amount);
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

        auto it = _exchangeRate.lower_bound(date);

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


