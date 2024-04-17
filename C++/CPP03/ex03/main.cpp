/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:15:21 by agustin           #+#    #+#             */
/*   Updated: 2024/04/17 16:55:04 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap diamondTrap1("DiamondTrap1");
	DiamondTrap diamondTrap2("DiamondTrap2");

	std::cout << std::endl;

	std::cout << diamondTrap1 << "\n" << diamondTrap2 << std::endl;

	std::cout << std::endl;

	diamondTrap1.attack("DiamondTrap2");
	diamondTrap2.takeDamage(diamondTrap1.getAttackDamage());

	std::cout << std::endl;

	std::cout << diamondTrap1 << "\n" << diamondTrap2 << std::endl;

	std::cout << std::endl;

	diamondTrap2.beRepaired(5);

	std::cout << std::endl;

	std::cout << diamondTrap1 << "\n" << diamondTrap2 << std::endl;

	std::cout << std::endl;

	diamondTrap2.highFivesGuys();
	diamondTrap1.whoAmI();

	std::cout << std::endl;

	return (0);
}