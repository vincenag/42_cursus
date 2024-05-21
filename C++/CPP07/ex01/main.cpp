/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:04:54 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/21 23:05:19 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void print(int const &i)
{
    std::cout << i << std::endl;
}

void printChar(char const &c)
{
    std::cout << c << std::endl;
}

void printString(std::string const &s)
{
    std::cout << s << std::endl;
}

int main()
{
    int intArray[5] = {1, 2, 3, 4, 5};
    char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
    std::string stringArray[5] = {"Hello", "World", "How", "Are", "You"};

    std::cout << "Printing intArray:" << std::endl;
    iter(intArray, 5, print);
    std::cout << "Printing charArray:" << std::endl;
    iter(charArray, 5, printChar);
    std::cout << "Printing stringArray:" << std::endl;
    iter(stringArray, 5, printString);
    return 0;
}
