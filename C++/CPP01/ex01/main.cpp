/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:55:06 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/18 12:42:17 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
    Zombie *zombies = zombieHorde(5, "Zombie");
    for (int i = 0; i < 5; i++){
        zombies[i].announce();
    }
    delete [] zombies;
    return 0;
}