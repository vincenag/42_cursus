/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:01:21 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/20 13:05:38 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bottom;

	if (*stack && (*stack)->next)
	{
		bottom = stack_bottom(*stack);
		tmp = *stack;
		while (tmp->next != bottom)
			tmp = tmp->next;
		tmp->next = NULL;
		bottom->next = *stack;
		*stack = bottom;
	}
}

void	rra(t_stack **stack_a)
{
	ft_rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	ft_rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_printf("rrr\n");
}
