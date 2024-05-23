/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:45:40 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/23 09:46:02 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack const &copy) : std::stack<T>(copy) {}
        virtual ~MutantStack() {}

        MutantStack &operator=(MutantStack const &copy)
        {
            if (this != &copy)
                std::stack<T>::operator=(copy);
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin()
        {
            return std::stack<T>::c.begin();
        }

        iterator end()
        {
            return std::stack<T>::c.end();
    }
};

#endif