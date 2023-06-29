/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:19:54 by agvincen          #+#    #+#             */
/*   Updated: 2023/06/29 13:14:58 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *data, ...);
int		ft_print_c(char c);
int		ft_print_s(char *string);
int		ft_print_p(void *ptr);
int		ft_print_d(int num);
int		ft_print_x(char data, unsigned long long np);
int		ft_print_u(unsigned int num);

#endif
