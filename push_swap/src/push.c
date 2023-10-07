/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:01:37 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/20 15:37:56 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (*stack_2)
	{
		tmp = *stack_2;
		*stack_2 = (*stack_2)->next;
		tmp->next = *stack_1;
		*stack_1 = tmp;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pb\n");
}