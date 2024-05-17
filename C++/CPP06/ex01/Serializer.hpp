/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:53:47 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/17 11:40:52 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

# include "Data.hpp"

class Serializer
{
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);

    private:
        Serializer();
        Serializer(Serializer const &src);
        Serializer &operator=(Serializer const &rhs);
        
        ~Serializer();

        //std::string _randomString(int length);
        //int _randomInt(void);
};

#endif

