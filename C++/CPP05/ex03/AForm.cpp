/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:35:50 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/10 14:07:17 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    _signed = false;
}

AForm::AForm(AForm const &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    *this = copy;
}

AForm::~AForm(void)
{
}

AForm &AForm::operator=(AForm const &rhs)
{
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

std::string const AForm::getName(void) const
{
    return _name;
}

bool AForm::getSigned(void) const
{
    return _signed;
}

int AForm::getGradeToSign(void) const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
    return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
    if (!_signed)
        throw AForm::FormNotSignedException();
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
    out << "AForm " << form.getName() << " is ";
    if (form.getSigned())
        out << "signed";
    else
        out << "not signed";
    out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
    return out;
}
