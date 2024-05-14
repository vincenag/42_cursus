/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:31:33 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/14 21:31:48 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <fstream>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm(void);

        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

        void execute(Bureaucrat const &executor) const;

    private:
        std::string _target;
};

#endif