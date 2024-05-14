/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:29:53 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/14 22:23:27 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try 
	{
        AForm *SCF = new ShrubberyCreationForm("home");
        Bureaucrat b1("Bob", 136);
        Bureaucrat b2("Jhon", 145);
        b2.signForm(*SCF);
        b1.executeForm(*SCF);

        b2.executeForm(*SCF);
        delete SCF;
    }
    
	catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try 
	{
        AForm *SCF = new RobotomyRequestForm("home");
        Bureaucrat b1("Bob2", 44);
        Bureaucrat b2("Jhon2", 72);
        b2.signForm(*SCF);
        b1.executeForm(*SCF);

        b2.executeForm(*SCF);
        delete SCF;
    }
    
	catch (std::exception & e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try 
	{
        AForm *SCF = new PresidentialPardonForm("home");
        Bureaucrat b1("Bob2", 5);
        Bureaucrat b2("Jhon2", 24);
        b2.signForm(*SCF);
        b1.executeForm(*SCF);

        b2.executeForm(*SCF);
        delete SCF;
    }
    
	catch (std::exception & e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
