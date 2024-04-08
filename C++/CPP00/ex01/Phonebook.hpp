/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:47:07 by agvincen          #+#    #+#             */
/*   Updated: 2024/04/08 13:54:09 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include "Contact.hpp"
#include <chrono>
#include <ctime> 

class Phonebook
{
    public:
        Contact contacts[8];

        void    add_contact();
        void    search_contact();
};

#endif