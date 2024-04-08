/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:47:52 by agvincen          #+#    #+#             */
/*   Updated: 2024/04/08 15:36:00 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

int main(int argc, char **argv)
{
    Phonebook phonebook;
    std :: string command;

    if (argc > 1)
    {
        std :: cout << "Usage: ./phonebook" << std :: endl;
        return 1;
    }

    while (1)
    {
        std :: cout << "Enter a command: \n->ADD\n->SEARCH\n->EXIT\n";
        if (!std::getline(std::cin, command)) // Se ha alcanzado el final del archivo (EOF)
        { 
            std::cout << "Exiting the program" << std::endl;
            break;
        }

        if (command == "ADD")
        {
            std :: cout << "Adding a contact" << std :: endl;
            phonebook.add_contact();
        }
        else if (command == "SEARCH")
        {
            std :: cout << "Searching for a contact" << std :: endl;
            phonebook.search_contact();
        }
        else if (command == "EXIT")
        {
            std :: cout << "Exiting the program" << std :: endl;
            break;
        }
        else
        {
            std :: cout << "Invalid command" << std :: endl;
        }
    }
    return 0;
}