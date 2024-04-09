/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:06:02 by agustin           #+#    #+#             */
/*   Updated: 2024/04/09 16:36:29 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
    if (argc != 1)
    {
        std::cout << "Usage: ./ex00" << std::endl;
        return 1;
    }
    Zombie *zombie = newZombie("Rick");
    zombie->announce();
    randomChump("Morty");
    delete zombie;
    return 0;
}
