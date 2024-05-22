/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:18:33 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/22 15:19:07 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    Array<int> a(5);
    Array<int> b(5);

    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i;
    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i + 5;

    std::cout << "a: ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    std::cout << "b: ";
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    Array<int> c(a);

    std::cout << "c: ";
    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    c = b;

    std::cout << "c: ";
    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    return 0;
}