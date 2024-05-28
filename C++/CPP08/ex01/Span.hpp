/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:41:35 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/28 16:41:15 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <list>

class Span
{
    public:
        Span(unsigned int N);
        Span(Span const & src);
        ~Span();

        Span & operator=(Span const & rhs);

        void addNumber(int n);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        void addManyNumbers(std::list<int>::iterator begin, std::list<int>::iterator end);

        class SpanFullException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class SpanNoSpanException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        Span();
        unsigned int _N;
        std::vector<int> _v;
};

#endif