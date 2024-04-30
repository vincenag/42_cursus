/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:39:59 by agustin           #+#    #+#             */
/*   Updated: 2024/04/29 16:40:29 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = copy.type;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this == &copy)
        return *this;
    this->type = copy.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}
