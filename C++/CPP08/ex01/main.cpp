/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:46:39 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/28 16:50:14 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    try{
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << "---------------------------------------" <<std::endl;

        //Chequeo con 10000 numeros

        Span sp2 = Span(10000);

        std::srand(std::time(0));

        std::list<int> randomNumbers;
        for (int i = 0; i < 10000; ++i) {
            randomNumbers.push_back(std::rand());
        }

        sp2.addManyNumbers(randomNumbers.begin(), randomNumbers.end());

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}