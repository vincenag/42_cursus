/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:12:22 by agvincen          #+#    #+#             */
/*   Updated: 2024/04/10 13:40:24 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter level" << std::endl;
		return (0);
	}

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && levels[i].compare(argv[1]))
		i++;

	switch(i)
	{
		case 0:
			harl.complain("DEBUG");
			break;
		case 1:
			harl.complain("INFO");
			break;
		case 2:
			harl.complain("WARNING");
			break;
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

		return (0);}
	}