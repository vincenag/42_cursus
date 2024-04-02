/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:02:54 by agustin           #+#    #+#             */
/*   Updated: 2024/04/02 18:34:19 by agustin          ###   ########.fr       */
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
    return this->_rawBits >> _bits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &val)
{
    o << val.toFloat();
    return o;
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return this->getRawBits() != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->_rawBits++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--(void)
{
    this->_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}

