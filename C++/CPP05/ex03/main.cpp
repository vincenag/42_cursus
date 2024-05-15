/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:29:53 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/15 18:44:26 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Intern intern;
    Bureaucrat b1("Bob", 136);
    Bureaucrat b2("Jhon", 145);
    AForm *form;

    try
    {
        form = intern.makeForm("shrubbery creation", "home");
        b2.signForm(*form);
        b1.executeForm(*form);
        b2.executeForm(*form);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "--------------------------------" << std::endl;
        form = intern.makeForm("robotomy request", "home");
        b2.signForm(*form);
        b1.executeForm(*form);
        b2.executeForm(*form);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "--------------------------------" << std::endl;
        form = intern.makeForm("presidential pardon", "home");
        b2.signForm(*form);
        b1.executeForm(*form);
        b2.executeForm(*form);
        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
