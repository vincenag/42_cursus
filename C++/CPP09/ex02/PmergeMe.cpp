/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:52:13 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/04 13:26:18 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _v(), _l() {}

PmergeMe::PmergeMe(PmergeMe const &src): _v(src._v), _l(src._l) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    if (this != &rhs) {
        _v = rhs._v;
        _l = rhs._l;
    }
    return *this;
}

void    PmergeMe::mergeSortVector(std::vector<int> &v) {
    _v = v;
    sortVector(_v, 0, _v.size() - 1);
    v = _v;
}

void    PmergeMe::sortVector(std::vector<int> &v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        sortVector(v, l, m);
        sortVector(v, m + 1, r);
        mergeVector(v, l, m, r);
    }
}

void    PmergeMe::mergeVector(std::vector<int> &v, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            v[k] = L[i++];
        else
            v[k] = R[j++];
        k++;
    }

    while (i < n1)
        v[k++] = L[i++];
    while (j < n2)
        v[k++] = R[j++];
}

void PmergeMe::mergeSortList(std::list<int>& lst) {
    if (lst.size() < 2) return;

    auto middle = lst.begin();
    std::advance(middle, lst.size() / 2);

    std::list<int> left(lst.begin(), middle);
    std::list<int> right(middle, lst.end());

    mergeSortList(left);
    mergeSortList(right);

    lst.clear();
    lst.splice(lst.end(), mergeList(left, right));
}

std::list<int> PmergeMe::mergeList(const std::list<int>& left, const std::list<int>& right) {
    std::list<int> merged;
    auto i = left.begin(), j = right.begin();

    while (i!= left.end() && j!= right.end()) {
        if (*i <= *j) {
            merged.emplace_back(*i++);
        } else {
            merged.emplace_back(*j++);
        }
    }

    while (i!= left.end()) {
        merged.emplace_back(*i++);
    }

    while (j!= right.end()) {
        merged.emplace_back(*j++);
    }

    return merged;
}
