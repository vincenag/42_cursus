/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:39:02 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/11 15:43:39 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {

    if (argc != 2){
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
    
    std::string dataFile = "data.csv";

    std::ifstream file(dataFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << dataFile << std::endl;
        return 1;
    }
    file.close();

    BitcoinExchange Base(dataFile);
    Base.exchange(argv[1]);

    return 0;
}