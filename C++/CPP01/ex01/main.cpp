/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:55:06 by agvincen          #+#    #+#             */
/*   Updated: 2024/04/09 16:36:50 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv){
    if (argc != 1){
        std::cout << "Usage: ./ex01" << std::endl;
        return 1;
    }
    Zombie *zombies = zombieHorde(5, "Zombie");
    for (int i = 0; i < 5; i++){
        zombies[i].announce();
    }
    delete [] zombies;
    return 0;
}