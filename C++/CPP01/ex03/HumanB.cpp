/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:25:36 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/18 16:26:17 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){
    return;
}

HumanB::~HumanB(){
    return;
}

void HumanB::attack(){
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
    return;
}

void HumanB::setWeapon(Weapon &weapon){
    this->_weapon = &weapon;
    return;
}
