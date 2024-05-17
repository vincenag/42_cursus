/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:31:41 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/17 14:01:54 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base *generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))  //si el puntero p es de tipo A, devuelve un puntero a A, si no, devuelve NULL
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A&>(p); //si falla, lanza una excepcion de tipo bad_cast
        //(void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            //(void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::bad_cast &e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                //(void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::bad_cast &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}
