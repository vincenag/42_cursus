/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:25:54 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/21 22:54:46 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>

template <typename T> // Se declara una plantilla (T es un tipo de dato genérico).
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
const T& min(const T& a, const T& b)
{
    return (a < b ? a : b);
}

template <typename T>
const T& max(const T& a, const T& b)
{
    return (a > b ? a : b);
}

#endif