/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:31:52 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/14 21:32:18 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomization failed" << std::endl;
}

