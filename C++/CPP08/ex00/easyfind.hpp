/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:02:31 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/28 10:22:32 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value) // T tiene un tipo miembro iterator (típico de contenedores de la STL)
{
    // Un iterador es un objeto que actúa como un puntero que puede usarse para 
    // acceder a los elementos de un contenedor secuencialmente. 
    
    typename T::iterator it = std::find(container.begin(), container.end(), value); // begin() y end() son miembros de T. Retornan iteradores.
    if (it == container.end())
        throw std::exception();
    return it;
}



#endif
