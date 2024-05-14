/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:46:13 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/14 22:56:10 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const &copy);
        ~Intern();
        Intern &operator=(Intern const &copy);

        AForm *makeForm(std::string const &name, std::string const &target);

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif