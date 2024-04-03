/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:26:57 by agustin           #+#    #+#             */
/*   Updated: 2024/04/03 18:51:50 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
    std::cout << "ClapTrap " << _name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    _name = copy._name;
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    return *this;
}

void ClapTrap::attack(std::string const & target)
{
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
        return;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no hit points left!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
    std::cout << "ClapTrap " << _name << " has " << _energyPoints << " energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage!" << std::endl;
    _hitPoints -= amount;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points left!" << std::endl;
        return;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no hit points left!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " has been repaired by " << amount << " points!" << std::endl;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hit points left!" << std::endl;
    _energyPoints -= 1;
    std::cout << "ClapTrap " << _name << " has " << _energyPoints << " energy points left!" << std::endl;
}
