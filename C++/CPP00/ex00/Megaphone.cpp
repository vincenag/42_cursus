/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:22:26 by agustin           #+#    #+#             */
/*   Updated: 2024/04/04 15:29:34 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
    if (argc == 1){
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    
	std::string input;
    std::string output;
    int aux = 1;

    while (aux < argc)
    {
        input += argv[aux];
        input += " ";
        aux++;
    }
    for(long unsigned int i = 0; i < input.length(); i++)
    {
        output += toupper(input[i]);
    }

	std::cout << output << std::endl;
	return (0);
}