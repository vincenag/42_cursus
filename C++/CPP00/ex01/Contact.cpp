/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:54:33 by agvincen          #+#    #+#             */
/*   Updated: 2024/04/09 13:38:39 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool Contact::isNumeric() {
    for (int i = 0; i < this->phone_number.length(); i++) {
        if (!std::isdigit(this->phone_number[i])) {
            return false;
        }
    }
    return true;
}

void Contact::ft_all_fields() 
{
    while (this->first_name.empty()) {
        std::cout << "First name is empty. Please enter a value: ";
        std::getline(std::cin, this->first_name);
    }
    while (this->last_name.empty()) {
        std::cout << "Last name is empty. Please enter a value: ";
        std::getline(std::cin, this->last_name);
    }
    while (this->nickname.empty()) {
        std::cout << "Nickname is empty. Please enter a value: ";
        std::getline(std::cin, this->nickname);
    }
    while (this->phone_number.empty() || !this->isNumeric()) {
        std::cout << "Phone number is empty or not numeric. Please enter a value: ";
        std::getline(std::cin, this->phone_number);
    }
    while (this->darkest_secret.empty()) {
        std::cout << "Darkest secret is empty. Please enter a value: ";
        std::getline(std::cin, this->darkest_secret);
    }
}