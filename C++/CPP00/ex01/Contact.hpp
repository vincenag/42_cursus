/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:52:17 by agvincen          #+#    #+#             */
/*   Updated: 2024/04/08 20:08:25 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
#include <chrono>
#include <ctime> 

class Contact
{
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        
        std::time_t timestamp;

        Contact(){
            this->first_name = "";
            this->last_name = "";
            this->nickname = "";
            this->phone_number = "";
            this->darkest_secret = "";
            this->timestamp = 0;};

        void ft_all_fields();
        bool isNumeric();
};

#endif