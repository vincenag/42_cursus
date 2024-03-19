/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:47:52 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/07 15:05:11 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    Phonebook phonebook;
    std :: string command;

    while (1)
    {
        std :: cout << "Enter a command: \n->ADD\n->SEARCH\n->EXIT\n";
        std :: cin >> command;
        if (command == "ADD")
        {
            std :: cout << "Adding a contact" << std :: endl;
            add_contact(&phonebook);
        }
        else if (command == "SEARCH")
        {
            std :: cout << "Searching for a contact" << std :: endl;
            search_contact(&phonebook);
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