/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:04:08 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/11 15:55:05 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cmath>
# include <sstream>
# include <stdlib.h>

class RPN
{
    public:
        RPN();
        RPN(const RPN &copy);
        ~RPN();
        RPN &operator=(const RPN &copy);

        double evaluate(const std::string &expression);

    private:
        std::stack<double>	_stack;
        void processToken(const std::string &token);
};

#endif