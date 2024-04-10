/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agustin <agustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:30:48 by agvincen          #+#    #+#             */
/*   Updated: 2024/04/10 18:19:05 by agustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &val); // Copy constructor
		~Fixed();
		Fixed &operator=(const Fixed &val2); // Assignation operator
	
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int					_rawBits;
		static const int	_bits = 8;
};

#endif