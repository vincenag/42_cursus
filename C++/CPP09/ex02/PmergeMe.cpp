/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:52:13 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/12 11:30:44 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(): _l(), _d() {}

PmergeMe::PmergeMe(PmergeMe const &src): _l(src._l), _d(src._d) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    if (this != &rhs) {
        _l = rhs._l;
        _d = rhs._d;
    }
    return *this;
}
