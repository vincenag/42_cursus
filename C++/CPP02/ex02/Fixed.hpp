/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:02:59 by agustin           #+#    #+#             */
/*   Updated: 2024/04/02 18:35:29 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>


class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed &src);
        ~Fixed(void);

        Fixed &operator=(const Fixed &rhs);

        int		getRawBits(void) const;
        void	setRawBits(int const raw);

        Fixed(const int integer);
        Fixed(const float floater);

        float	toFloat(void) const;
        int		toInt(void) const;

        bool    operator>(const Fixed &rhs) const;
        bool    operator<(const Fixed &rhs) const;
        bool    operator>=(const Fixed &rhs) const;
        bool    operator<=(const Fixed &rhs) const;
        bool    operator==(const Fixed &rhs) const;
        bool    operator!=(const Fixed &rhs) const;

        Fixed   operator+(const Fixed &rhs) const;
        Fixed   operator-(const Fixed &rhs) const;
        Fixed   operator*(const Fixed &rhs) const;
        Fixed   operator/(const Fixed &rhs) const;

        Fixed   &operator++(void);
        Fixed   operator++(int);
        Fixed   &operator--(void);
        Fixed   operator--(int);

        static Fixed    &min(Fixed &a, Fixed &b);
        static Fixed    &max(Fixed &a, Fixed &b);
        static const Fixed    &min(const Fixed &a, const Fixed &b);
        static const Fixed    &max(const Fixed &a, const Fixed &b);

    private:
        int					_rawBits;
        static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &o, const Fixed &rhs);

#endif