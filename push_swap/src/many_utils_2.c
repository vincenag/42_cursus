/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:00:54 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/28 01:26:41 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_tar_pos(t_stack *temp_a, t_stack *temp_b, int *diff)
{
    while (temp_a)
    {
        if (temp_b->index < temp_a->index)
        {
            if (temp_a->index - temp_b->index <= *diff)
            {
                *diff = temp_a->index - temp_b->index;
                temp_b->target_pos = temp_a->pos;
            }
        }
        temp_a = temp_a->next;
    }
}

int ft_odd(int  size)
{
    int aux;

    if (size % 2 == 0)
        aux = size / 2;
    else
        aux = (size / 2) + 1;
    return (aux);
}

int	num_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

t_stack *find_cheapest(t_stack **stack_b)
{
    t_stack *temp_b;
    t_stack *cheapest;

    temp_b = *stack_b;
    cheapest = temp_b;
    while (temp_b)
    {
        if (num_abs(temp_b->cost_a) + num_abs(temp_b->cost_b) < num_abs(cheapest->cost_a) + num_abs(cheapest->cost_b))
            cheapest = temp_b;
        temp_b = temp_b->next;
    }
    return (cheapest);
}
