/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:15:21 by agustin           #+#    #+#             */
/*   Updated: 2024/04/16 20:39:22 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	ScavTrapA("ScavTrapA");
	ScavTrap	ScavTrapB("ScavTrapB");

	std::cout << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	std::cout << std::endl;

	ScavTrapA.attack("ScavTrapB");
	ScavTrapB.takeDamage(ScavTrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	std::cout << std::endl;

	ScavTrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	std::cout << std::endl;

	ScavTrapB.guardGate();

	std::cout << std::endl;

	return (0);
}