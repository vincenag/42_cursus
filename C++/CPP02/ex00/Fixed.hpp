/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:30:48 by agvincen          #+#    #+#             */
/*   Updated: 2024/03/22 13:14:33 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &val);
		~Fixed();
		Fixed &operator=(const Fixed &val2);
	
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int					_rawBits;
		static const int	_bits = 8;
};

#endif