/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:02:33 by agustin           #+#    #+#             */
/*   Updated: 2024/05/03 15:14:53 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(AMateria const & src)
{
    *this = src;
}

AMateria::~AMateria()
{
}

AMateria & AMateria::operator=(AMateria const & src)
{
    if (this != &src)
    {
        this->_type = src._type;
    }
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}
