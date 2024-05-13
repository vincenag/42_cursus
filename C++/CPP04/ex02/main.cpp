/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:23:15 by agustin           #+#    #+#             */
/*   Updated: 2024/05/03 14:44:19 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
	//const Animal*	animal = new Animal();

    delete j;//should not create a leak
    delete i;

    std::cout << std::endl;
    
	int		len = 10;
	int		k = 0;
	Animal	*tab[len];

	while (k < (len / 2))
	{
		tab[k] = new Dog();
		k++;
	}
	while (k < len)
	{
		tab[k] = new Cat();
		k++;
	}
	while (--k >= 0)
		delete tab[k];
	return (0);
}
