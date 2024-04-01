/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:32:31 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/22 17:35:26 by agvincen         ###   ########.fr       */
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

    private:
        int					_rawBits;
        static const int	_bits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif