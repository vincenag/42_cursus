/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:32:21 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/28 12:16:43 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &val)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(val.getRawBits());
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& val2)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(val2.getRawBits());
    return *this;
}

int Fixed::getRawBits(void) const
{
    return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}

Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = integer << _bits;
}

Fixed::Fixed(const float floater)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(floater * (1 << _bits));
    
}

float Fixed::toFloat(void) const
{
    return (float)this->_rawBits / (1 << _bits);
}

int Fixed::toInt(void) const
{
    //std::cout << "Original value" << _rawBits << std::endl;
    return this->_rawBits >> _bits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &val)
{
    o << val.toFloat();
    return o;
}