/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:45:29 by agvincen          #+#    #+#             */
/*   Updated: 2024/05/28 16:49:11 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>


Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(Span const & src)
{
    *this = src;
}

Span::~Span()
{
}

Span & Span::operator=(Span const & rhs)
{
    if (this != &rhs)
    {
        _N = rhs._N;
        _v = rhs._v;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (_v.size() >= _N)
        throw SpanFullException();
    _v.push_back(n);
}

unsigned int Span::shortestSpan()
{
    if (_v.size() <= 1)
        throw SpanNoSpanException();
    std::sort(_v.begin(), _v.end());
    unsigned int min = UINT_MAX;
    for (std::vector<int>::iterator it = _v.begin(); it != _v.end() - 1; it++)
    {
        if (static_cast<unsigned int>(*(it + 1) - *it) < min)
            min = *(it + 1) - *it;
    }
    return min;
}

unsigned int Span::longestSpan()
{
    if (_v.size() <= 1)
        throw SpanNoSpanException();
    std::sort(_v.begin(), _v.end());
    return static_cast<unsigned int>(_v.back() - _v.front());
}

const char* Span::SpanFullException::what() const throw()
{
    return "Span is full";
}

const char* Span::SpanNoSpanException::what() const throw()
{
    return "No span to find";
}

void Span::addManyNumbers(std::list<int>::iterator begin, std::list<int>::iterator end)
{
    if (std::distance(begin, end) > static_cast<int>(_N - _v.size()))
        throw SpanFullException();
    _v.insert(_v.end(), begin, end);
}
