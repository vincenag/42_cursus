/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:01:06 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/22 15:18:26 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        ~Array();

        Array &operator=(const Array &rhs);
        T &operator[](unsigned int n);

        unsigned int size() const;
    private:
        T *_array;
        unsigned int _size;
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &src) : _array(new T[src._size]), _size(src._size) {
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = src._array[i];

}

template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs) {
    if (this == &rhs)
        return *this;
    if (_array)
        delete[] _array;
    _array = new T[rhs._size];
    _size = rhs._size;
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = rhs._array[i];
    return *this;
}

template <typename T>
Array<T>::~Array() {
    if (_array)
        delete[] _array;
}

template <typename T>
T &Array<T>::operator[](unsigned int n) {
    if (n >= _size)
        throw std::exception();
    return _array[n];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif