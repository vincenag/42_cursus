/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:22:26 by agustin           #+#    #+#             */
/*   Updated: 2024/03/12 17:22:29 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
    if (argc < 2){
        return (1);
    }
	std::string input = argv[1];
    std::string output;

    for(long unsigned int i = 0; i < input.length(); i++)
    {
        output += toupper(input[i]);
    }
	std::cout << output << std::endl;
	return (0);
}