/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:55:21 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/18 13:01:56 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
public:
    Zombie(std::string name);
    Zombie(void);

    void announce(void);
    void setName(std::string name);

    ~Zombie(void);

private:
    std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif