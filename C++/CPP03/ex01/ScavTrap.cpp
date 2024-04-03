/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:15:01 by agustin           #+#    #+#             */
/*   Updated: 2024/04/03 23:43:53 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _name("ScavTrap"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
    std::cout << "ScavTrap " << _name << " is here!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
    std::cout << "ScavTrap " << _name << " is here!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    *this = copy;
    std::cout << "ScavTrap " << _name << " is here!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " is no more!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    _name = copy._name;
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    return *this;
}

void ScavTrap::attack(std::string const & target)
{
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}


void ScavTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    _hitPoints += amount;
    std::cout << "ScavTrap " << _name << " is repaired by " << amount << " points!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode!" << std::endl;
}

std::string ScavTrap::getName()
{
    return _name;
}

int ScavTrap::getHitPoints()
{
    return _hitPoints;
}

int ScavTrap::getEnergyPoints()
{
    return _energyPoints;
}

int ScavTrap::getAttackDamage()
{
    return _attackDamage;
}

void ScavTrap::setName(std::string name)
{
    _name = name;
}

void ScavTrap::setHitPoints(int hitPoints)
{
    _hitPoints = hitPoints;
}

void ScavTrap::setEnergyPoints(int energyPoints)
{
    _energyPoints = energyPoints;
}

void ScavTrap::setAttackDamage(int attackDamage)
{
    _attackDamage = attackDamage;
}
