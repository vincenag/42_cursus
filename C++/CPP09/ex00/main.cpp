/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:39:02 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/30 20:04:22 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {

    if (argc != 2){
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
    
    BitcoinExchange Base("data.csv");
    Base.exchange(argv[1]);

    return 0;
}