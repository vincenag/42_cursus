/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:53:28 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/17 11:41:43 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *data = new Data();
    uintptr_t raw = Serializer::serialize(data);
    Data *ptr = Serializer::deserialize(raw);

    std::cout << "Data: " << data << std::endl;
    std::cout << "Raw: " << raw << std::endl;
    std::cout << "Ptr: " << ptr << std::endl;

    delete data;
    return 0;
}