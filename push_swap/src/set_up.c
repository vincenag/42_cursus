/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:16:59 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/27 19:16:09 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stack_new(t_stack *stack, int value, int pos)
{
	t_stack	*new;
	t_stack	*current;

	new = ft_calloc(1, sizeof(t_stack));
	new->value = value;
	new->pos = pos;
	new->next = NULL;
	if (stack == NULL)
		return (new);
	current = stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (stack);
}

void	ft_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = stack;
	while (current)
	{
		tmp = stack;
		current->index = 1;
		while (tmp)
		{
			if (tmp->value < current->value)
				current->index++;
			tmp = tmp->next;
		}
		current = current->next;
	}
}

int	ft_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index != tmp->pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_list_size(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	temp = *stack;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
