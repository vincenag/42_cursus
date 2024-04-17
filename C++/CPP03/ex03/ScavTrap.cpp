/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:15:01 by agustin           #+#    #+#             */
/*   Updated: 2024/04/17 17:05:33 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->getName() << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
    *this = copy;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap "<< this->getName() <<" destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    std::cout << "ScavTrap assignation operator called" << std::endl;
    return (*this);
}

void ScavTrap::attack(std::string const & target) {
    if (this->getEnergyPoints() <= 0)
    {
        std::cout << "ScavTrap " << this->getName() << " has no energy points" << std::endl;
        return ;
    }
    else if (this->getHitPoints() <= 0)
    {
        std::cout << "ScavTrap " << this->getName() << " has no hit points" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->getName() << " attack " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " have enterred in Gate keeper mode" << std::endl;
}