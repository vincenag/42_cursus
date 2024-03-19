/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:06:02 by agustin           #+#    #+#             */
/*   Updated: 2024/03/12 17:06:48 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
    Zombie *zombie = newZombie("Rick");
    zombie->announce();
    randomChump("Morty");
    delete zombie;
    return 0;
}
