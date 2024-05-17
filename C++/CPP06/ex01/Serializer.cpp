/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:53:43 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/17 11:41:26 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *ptr = reinterpret_cast<Data *>(raw);
    return ptr;
}

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &src)
{
    *this = src;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

Serializer::~Serializer()
{
}
