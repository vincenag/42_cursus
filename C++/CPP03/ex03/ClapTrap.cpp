/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:15:06 by agustin           #+#    #+#             */
/*   Updated: 2024/04/16 21:51:20 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << this->getName() << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << this->getName() << " has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->getName() << " has been destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    return (*this);
}


std::ostream	&operator<<(std::ostream &stream, ClapTrap &clapTrap)
{
	stream << "Name: " << clapTrap.getName() << ", " <<\
	" Hit points: " << clapTrap.getHitPoints() <<  ", " <<\
	" Energy Points: " << clapTrap.getEnergyPoints() << ", " <<\
	" Attack Damage: " << clapTrap.getAttackDamage();
	return (stream);
}

std::string ClapTrap::getName()
{
    return (_name);
}

int ClapTrap::getHitPoints()
{
    return (_hitPoints);
}

int ClapTrap::getEnergyPoints()
{
    return (_energyPoints);
}

int ClapTrap::getAttackDamage()
{
    return (_attackDamage);
}

void ClapTrap::attack(std::string const & target)
{
    if (this->getEnergyPoints() <= 0)
    {
        std::cout << "ClapTrap " << this->getName() << " has no energy points left!" << std::endl;
        return;
    }
    else if (this->getHitPoints() <= 0)
    {
        std::cout << "ClapTrap " << this->getName() << " has no hit points left!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
    if (this->getHitPoints() < 0)
        this->_hitPoints = 0;
    std::cout << "ClapTrap " << this->getName() << " has taken " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->getEnergyPoints() <= 0)
    {
        std::cout << "ClapTrap " << this->getName() << " has no energy points left!" << std::endl;
        return;
    }
    else if (this->getHitPoints() <= 0)
    {
        std::cout << "ClapTrap " << this->getName() << " has no hit points left!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->getName() << " has been repaired by " << amount << " points!" << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
}
