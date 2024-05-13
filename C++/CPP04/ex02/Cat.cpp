/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:52:29 by agustin           #+#    #+#             */
/*   Updated: 2024/05/03 14:38:59 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
    this->_brain = new Brain();
}
Cat::Cat(const Cat &copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = copy.type;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignation operator called" << std::endl;
    if (this == &copy)
        return *this;
    this->type = copy.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}
