/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:46:04 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/14 22:58:19 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{
}

Intern::Intern(Intern const &copy)
{
    *this = copy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &copy)
{
    (void)copy;
    return (*this);
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

    for (int i = 0; i < 3; i++)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (forms[i]);
        }
        delete forms[i];
    }
    throw Intern::FormNotFoundException();
    return (NULL);
}

