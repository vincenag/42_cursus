/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:24:29 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/18 16:25:32 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){
    return;
}

HumanA::~HumanA(){
    return;
}

void HumanA::attack(){
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
    return;
}
