/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:32:01 by agvincen          #+#    #+#             */
/*   Updated: 2023/10/03 12:48:40 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	ft_clear(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && (str[i + 1]) == '\0')
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *stack, int num)
{
	t_stack	*current;
	int		i;

	current = stack;
	i = 0;
	while (current)
	{
		if (current->value == num)
			i++;
		current = current->next;
	}
	return (i);
}

t_stack	*stack_bottom(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
		current = current->next;
	return (current);
}
