/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:55:19 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/18 13:27:34 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
    this->_name = name;
    std::cout << this->_name << " has been created" << std::endl;
}

Zombie::Zombie(void){
    this->_name = "Zombie default";
    std::cout << this->_name << " has been created" << std::endl;
}

void Zombie::announce(void){
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
    this->_name = name;
}

Zombie::~Zombie(void){
    std::cout << this->_name << " has died" << std::endl;
}