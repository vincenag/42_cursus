/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:17:46 by agustin           #+#    #+#             */
/*   Updated: 2024/05/02 19:18:24 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default")
{
    for (int i = 0; i < 4; i++)
        _materias[i] = 0;
}

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _materias[i] = 0;
}

Character::Character(Character const & src)
{
    *this = src;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
            delete _materias[i];
    }
}

Character & Character::operator=(Character const & src)
{
    if (this != &src)
    {
        _name = src._name;
        for (int i = 0; i < 4; i++)
        {
            if (_materias[i])
                delete _materias[i];
            _materias[i] = src._materias[i]->clone();
        }
    }
    return *this;
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _materias[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _materias[idx])
        _materias[idx]->use(target);
}
