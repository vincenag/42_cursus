/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:34:27 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/22 17:35:32 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
        lst.push_back(i);
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Value found in vector: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value not found in vector" << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << "Value found in list: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value not found in list" << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Value found in vector: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value not found in vector" << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(lst, 42);
        std::cout << "Value found in list: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Value not found in list" << std::endl;
    }

    return 0;
}