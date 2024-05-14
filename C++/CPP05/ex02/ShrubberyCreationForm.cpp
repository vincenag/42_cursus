/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:31:10 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/14 21:13:50 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream file(_target + "_shrubbery");
    file << "      /\\      " << std::endl;
    file << "     /\\*\\     " << std::endl;
    file << "    /\\O\\*\\    " << std::endl;
    file << "   /*/\\/\\/\\   " << std::endl;
    file << "  /\\O\\/\\*\\/\\  " << std::endl;
    file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file << "      ||      " << std::endl;
    file.close();
}
