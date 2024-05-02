/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:54:55 by agustin           #+#    #+#             */
/*   Updated: 2024/05/02 19:55:57 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materias[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    for (int i = 0; i < 4; i++)
        _materias[i] = src._materias[i]->clone();
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _materias[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src)
{
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
            delete _materias[i];
        for (int i = 0; i < 4; i++)
            _materias[i] = src._materias[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] == 0)
        {
            _materias[i] = materia;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] != 0 && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return 0;
}
