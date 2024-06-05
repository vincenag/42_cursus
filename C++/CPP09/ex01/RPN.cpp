/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:05:36 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/05 13:22:25 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
    {
        this->_stack = copy._stack;
    }
    return *this;
}

double RPN::evaluate(const std::string &expression)
{
    std::string token;
    std::istringstream iss(expression);

    while (iss >> token)
    {
        processToken(token);
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    return _stack.top();
}

void RPN::processToken(const std::string &token)
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
    {
        if (_stack.size() < 2)
            throw std::runtime_error("Error");

        double op1 = _stack.top();
        _stack.pop();
        double op2 = _stack.top();
        _stack.pop();

        if (token == "+")
            _stack.push(op2 + op1);
        else if (token == "-")
            _stack.push(op2 - op1);
        else if (token == "*")
            _stack.push(op2 * op1);
        else if (token == "/")
        {
            if (op1 == 0)
                throw std::runtime_error("Division by zero");
            else
                _stack.push(op2 / op1);
        }
    }
    else
    {
        try
        {
            _stack.push(std::stod(token));
        }
        catch (const std::invalid_argument &)
        {
            throw std::runtime_error("Error");
        }
    }
}