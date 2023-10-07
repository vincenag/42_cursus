/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:07:22 by agvincen          #+#    #+#             */
/*   Updated: 2023/10/02 19:40:57 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*max_index(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*max;

	temp = *stack;
	max = *stack;
	temp = temp->next;
	while (temp)
	{
		if (temp->value > max->value)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_stack	*min_index(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*min;

	temp = *stack;
	min = *stack;
	temp = temp->next;
	while (temp)
	{
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	ft_pos(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 1;
	temp = *stack;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

void	ft_three(t_stack **stack)
{
	t_stack	*max;

	ft_pos(stack);
	max = max_index(stack);
	if (max->pos == 1)
		ra(stack);
	else if (max->pos == 2)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	ft_many(t_stack **stack_a, t_stack **stack_b)
{
	first_step(stack_a, stack_b);
	ft_three(stack_a);
	while (*stack_b)
	{
		ft_pos(stack_a);
		ft_pos(stack_b);
		second_step(stack_a, stack_b);
		third_step(stack_a, stack_b);
		fourth_step(stack_a, stack_b);
	}
	if (!ft_sorted(stack_a))
		last_step(stack_a);
}
