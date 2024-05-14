/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:30:02 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/14 16:30:20 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name)
{
    *this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
        _grade = rhs._grade;
    return *this;
}

std::string const Bureaucrat::getName(void) const
{
    return _name;
}

int Bureaucrat::getGrade(void) const
{
    return _grade;
}

void Bureaucrat::incrementGrade(void)
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
