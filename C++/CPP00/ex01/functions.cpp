/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:31:17 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/07 17:43:21 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void ft_all_fields(Contact& contact) 
{
    while (contact.first_name.empty()) {
        std::cout << "First name is empty. Please enter a value: ";
        std::getline(std::cin, contact.first_name);
    }
    while (contact.last_name.empty()) {
        std::cout << "Last name is empty. Please enter a value: ";
        std::getline(std::cin, contact.last_name);
    }
    while (contact.nickname.empty()) {
        std::cout << "Nickname is empty. Please enter a value: ";
        std::getline(std::cin, contact.nickname);
    }
    while (contact.phone_number.empty()) {
        std::cout << "Phone number is empty. Please enter a value: ";
        std::getline(std::cin, contact.phone_number);
    }
    while (contact.darkest_secret.empty()) {
        std::cout << "Darkest secret is empty. Please enter a value: ";
        std::getline(std::cin, contact.darkest_secret);
    }
}

void    add_contact(Phonebook *phonebook)
{
    int i = 0;

    while (i < 7)
    {
        if (phonebook->contacts[i].first_name.empty())
            break;
        i++;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter the first name: ";
    std::getline(std::cin, phonebook->contacts[i].first_name);

    std::cout << "Enter the last name: ";
    std::getline(std::cin, phonebook->contacts[i].last_name);

    std::cout << "Enter the nickname: ";
    std::getline(std::cin, phonebook->contacts[i].nickname);

    std::cout << "Enter the phone number: ";
    std::getline(std::cin, phonebook->contacts[i].phone_number);

    std::cout << "Enter the darkest secret: ";
    std::getline(std::cin, phonebook->contacts[i].darkest_secret);

    ft_all_fields(phonebook->contacts[i]);
    std::cout << "Contact added succesfully" << std::endl;
}

void    search_contact(Phonebook *phonebook)
{
    int i = 0;

    std :: cout << std :: setw(10) << "Index" << "|";
    std :: cout << std :: setw(10) << "First name" << "|";
    std :: cout << std :: setw(10) << "Last name" << "|";
    std :: cout << std :: setw(10) << "Nickname" << std :: endl;

    while (i < 8)
    {
        if (!phonebook->contacts[i].first_name.empty())
        {
            std::cout << std::setw(10) << i << "|";
            if (phonebook->contacts[i].first_name.length() > 10)
                std::cout << phonebook->contacts[i].first_name.substr(0, 9) << '.' << "|";
            else
                std::cout << std::setw(10) << std::right << phonebook->contacts[i].first_name << "|";

            if (phonebook->contacts[i].last_name.length() > 10)
                std::cout << phonebook->contacts[i].last_name.substr(0, 9) << '.' << "|";
            else
                std::cout << std::setw(10) << std::right << phonebook->contacts[i].last_name << "|";

            if (phonebook->contacts[i].nickname.length() > 10)
                std::cout << phonebook->contacts[i].nickname.substr(0, 9) << '.' << std::endl;
            else
                std::cout << std::setw(10) << std::right << phonebook->contacts[i].nickname << std::endl;
        }
        i++;
    }
    
    std :: cout << "Enter the index of the contact: ";
    std :: cin >> i;
    if (i >= 0 && i < 8 && !phonebook->contacts[i].first_name.empty())
    {
        std :: cout << "First name: " << phonebook->contacts[i].first_name << std :: endl;
        std :: cout << "Last name: " << phonebook->contacts[i].last_name << std :: endl;
        std :: cout << "Nickname: " << phonebook->contacts[i].nickname << std :: endl;
        std :: cout << "Phone number: " << phonebook->contacts[i].phone_number << std :: endl;
        std :: cout << "Darkest secret: " << phonebook->contacts[i].darkest_secret << std :: endl;
    }
    else
    {
        std :: cout << "Invalid index" << std :: endl;
    }

}