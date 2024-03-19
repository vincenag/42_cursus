/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:23:24 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/19 13:21:27 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    return;
}

Harl::~Harl()
{
    return;
}

void    Harl::debug()
{
    std::cout << CYAN << "Debug" << DEFAULT << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
}

void    Harl::info()
{
    std::cout << YELLOW << "Info" << DEFAULT << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning()
{
    std::cout << MAGENTA << "Warning" << DEFAULT << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error()
{
    std::cout << RED << "Error" << DEFAULT << std::endl;
    std::cout << "This is unacceptable. I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    void    (Harl::*complaints[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*complaints[i])();
            return;
        }
    }
}