/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:37:47 by agustin           #+#    #+#             */
/*   Updated: 2024/04/03 18:46:28 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("2.0");

    clapTrap.attack("enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);

    std::cout << std::endl;
    clapTrap.takeDamage(10);
    clapTrap.attack("enemy");
    clapTrap.beRepaired(5);
    return 0;
}