/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:11:31 by agvincen          #+#    #+#             */
/*   Updated: 2024/04/10 13:40:28 by agustin          ###   ########.fr       */
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
    std::cout << CYAN << "[ DEBUG ]" << DEFAULT << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n" << std::endl;
}

void    Harl::info()
{
    std::cout << YELLOW << "[ INFO ]" << DEFAULT << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void    Harl::warning()
{
    std::cout << MAGENTA << "[ WARNING ]" << DEFAULT << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void    Harl::error()
{
    std::cout << RED << "[ ERROR ]" << DEFAULT << std::endl;
    std::cout << "This is unacceptable. I want to speak to the manager now.\n" << std::endl;
}

void    Harl::complain(std::string level)
{
    void    (Harl::*complaints[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    bool found = false;
    for (int i = 0; i < 4; i++)
    {
        if (found || level == levels[i])
        {
            (this->*complaints[i])();
            found = true;
        }
    }
}
