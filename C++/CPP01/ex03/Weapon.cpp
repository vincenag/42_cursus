/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:23:17 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/18 16:23:57 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){
    return;
}

Weapon::~Weapon(){
    return;
}

const std::string &Weapon::getType() const{
    return this->_type;
}

void Weapon::setType(std::string type){
    this->_type = type;
    return;
}
