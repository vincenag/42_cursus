/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:30:05 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/15 16:54:23 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        ~Bureaucrat(void);

        Bureaucrat &operator=(Bureaucrat const &rhs);

        std::string const getName(void) const;
        int getGrade(void) const;

        void incrementGrade(void);
        void decrementGrade(void);

        void signForm(AForm &Aform);

        void executeForm(AForm const &form);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        Bureaucrat(void);
        std::string const _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif