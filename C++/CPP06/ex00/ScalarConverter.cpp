/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:56:03 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/13 18:25:07 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
    *this = copy;
    return ;
}

ScalarConverter::~ScalarConverter(void)
{
    return ;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return (*this);
}

void	ScalarConverter::convert(const std::string &value)
{
    std::cout << "Conversion of " << value << std::endl;
    return ;
}


