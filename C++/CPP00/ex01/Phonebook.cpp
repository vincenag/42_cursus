/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:31:17 by agvincen          #+#    #+#             */
/*   Updated: 2024/04/09 13:44:59 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"


void    Phonebook::add_contact()
{
    std::chrono::system_clock::time_point current_time = std::chrono::system_clock::now();
    //auto current_time = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(current_time);

    int empty_index = 0;
    bool found_empty = false;

    // Buscar un índice vacío o el más antiguo si la agenda está llena
    for (int i = 0; i < 8; ++i) {
        if (contacts[i].first_name.empty()) {
            empty_index = i;
            found_empty = true;
            break;
        } else if (contacts[i].timestamp < contacts[empty_index].timestamp) {
            empty_index = i;
        }
    }

    std::cout << "Enter the first name: ";
    std::getline(std::cin, this->contacts[empty_index].first_name);

    std::cout << "Enter the last name: ";
    std::getline(std::cin, this->contacts[empty_index].last_name);

    std::cout << "Enter the nickname: ";
    std::getline(std::cin, this->contacts[empty_index].nickname);

    std::cout << "Enter the phone number: ";
    std::getline(std::cin, this->contacts[empty_index].phone_number);

    std::cout << "Enter the darkest secret: ";
    std::getline(std::cin, this->contacts[empty_index].darkest_secret);

    this->contacts[empty_index].timestamp = timestamp;

    (this->contacts[empty_index]).ft_all_fields();
    std::cout << "Contact added succesfully" << std::endl;
}

bool isInteger(const std::string& s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
    char* p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

void    Phonebook::search_contact()
{
    int i = 0;

    std :: cout << std :: setw(10) << "Index" << "|";
    std :: cout << std :: setw(10) << "First name" << "|";
    std :: cout << std :: setw(10) << "Last name" << "|";
    std :: cout << std :: setw(10) << "Nickname" << std :: endl;

    while (i < 8)
    {
        if (!this->contacts[i].first_name.empty())
        {
            std::cout << std::setw(10) << i << "|";
            if (this->contacts[i].first_name.length() > 10)
                std::cout << this->contacts[i].first_name.substr(0, 9) << '.' << "|";
            else
                std::cout << std::setw(10) << std::right << this->contacts[i].first_name << "|";

            if (this->contacts[i].last_name.length() > 10)
                std::cout << this->contacts[i].last_name.substr(0, 9) << '.' << "|";
            else
                std::cout << std::setw(10) << std::right << this->contacts[i].last_name << "|";

            if (this->contacts[i].nickname.length() > 10)
                std::cout << this->contacts[i].nickname.substr(0, 9) << '.' << std::endl;
            else
                std::cout << std::setw(10) << std::right << this->contacts[i].nickname << std::endl;
        }
        i++;
    }
    
    std :: cout << "Enter the index of the contact: ";
    std::string input;
    std :: getline(std :: cin, input);

    if (isInteger(input))
        i = std::stoi(input);
    else
        i = -1;

    std::cin.clear();

    if (i >= 0 && i < 8 && !this->contacts[i].first_name.empty())
    {
        std :: cout << "First name: " << this->contacts[i].first_name << std :: endl;
        std :: cout << "Last name: " << this->contacts[i].last_name << std :: endl;
        std :: cout << "Nickname: " << this->contacts[i].nickname << std :: endl;
        std :: cout << "Phone number: " << this->contacts[i].phone_number << std :: endl;
        std :: cout << "Darkest secret: " << this->contacts[i].darkest_secret << std :: endl;
    }
    else
    {
        std :: cout << "Invalid index" << std :: endl;
    }

}