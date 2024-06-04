/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:38:15 by agvincen          #+#    #+#             */
/*   Updated: 2024/06/04 13:34:58 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <algorithm>
# include <chrono>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(PmergeMe const &src);
        ~PmergeMe();

        PmergeMe &operator=(PmergeMe const &rhs);

        void    mergeSortVector(std::vector<int> &v);
        void    mergeSortList(std::list<int> &l);


    private:
        std::list<int>  _l;
        std::vector<int> _v;

        void    sortVector(std::vector<int> &v, int l, int r);
        void    mergeVector(std::vector<int> &v, int l, int m, int r);

        std::list<int>  mergeList(const std::list<int> &left, const std::list<int> &right);
};

#endif
