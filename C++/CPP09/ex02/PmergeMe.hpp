/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:38:15 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/06 13:35:35 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <algorithm>
# include <chrono>
# include <deque>


class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(PmergeMe const &src);
        ~PmergeMe();

        PmergeMe &operator=(PmergeMe const &rhs);
    
        template <typename Container>
        void mergeSort(Container &lst){
            if (lst.size() <= 1)
                return;

            auto mid = lst.begin();
            std::advance(mid, lst.size() / 2);

            Container left(lst.begin(), mid);
            Container right(mid, lst.end());

            mergeSort(left);
            mergeSort(right);

            lst = merge(left, right);
        }

    private:
        std::list<int>  _l;
        std::deque<int> _d;

        template <typename Container>
        Container merge(const Container &left, const Container &right){
            Container merged;
            auto i = left.begin(), j = right.begin();

            while (i != left.end() && j != right.end()) {
                if (*i <= *j) {
                    merged.emplace_back(*i++);
                } else {
                    merged.emplace_back(*j++);
                }
            }

            while (i != left.end()) {
                merged.emplace_back(*i++);
            }

            while (j != right.end()) {
                merged.emplace_back(*j++);
            }

            return merged;
        }
};

template void PmergeMe::mergeSort<std::list<int>>(std::list<int> &lst);
template void PmergeMe::mergeSort<std::deque<int>>(std::deque<int> &lst);
#endif
