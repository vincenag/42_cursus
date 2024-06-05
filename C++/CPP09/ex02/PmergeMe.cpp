/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:52:13 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/05 17:12:31 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(): _d(), _l() {}

PmergeMe::PmergeMe(PmergeMe const &src): _d(src._d), _l(src._l) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    if (this != &rhs) {
        _d = rhs._d;
        _l = rhs._l;
    }
    return *this;
}
