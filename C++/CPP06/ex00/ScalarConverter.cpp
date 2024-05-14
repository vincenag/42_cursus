/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:56:03 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/14 14:33:20 by agvincen         ###   ########.fr       */
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
    std::string specialTypes[6] = 
    {
        "-inff", "+inff", "nanf",
        "-inf", "+inf", "nan"
    };

    //Manejo de un solo carácter imprimible no numérico
    if (value.length() == 1 && !isdigit(value[0]) && isprint(value[0])) 
    {
        std::cout << "char: '" << value << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value[0]) << ".0" << std::endl;
        return;
    } 
    // Manejo de valores especiales
    for (const std::string& special : specialTypes)
    {
        if (value == special)
        {
            if (value == "-inff" || value == "+inff" || value == "nanf")
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << value << std::endl;
                std::cout << "double: " << value.substr(0, value.length() - 1) << std::endl;
            }
            else if (value == "-inf" || value == "+inf" || value == "nan")
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << value << "f" << std::endl;
                std::cout << "double: " << value << std::endl;
            }
            return;
        }
    }

    try 
    {
        // Intentar convertir a float primero
        float f = std::stof(value);

        std::cout << "char: ";
        if (static_cast<int>(f) < 32 || static_cast<int>(f) > 126)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(static_cast<int>(f)) << "'" << std::endl;

        std::cout << "int: " << static_cast<int>(f) << std::endl;
        if (f == static_cast<int>(f))
        {
            std::cout << "float: " << f << ".0f" << std::endl;
            std::cout << "double: " << f << ".0" << std::endl;
        }
        else
        {
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << f << std::endl;
        }
    } 
    catch (const std::invalid_argument&) 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    } 
    catch (const std::out_of_range&) 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }

    return;
}
