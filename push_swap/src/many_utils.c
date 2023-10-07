/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:40:49 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/28 01:09:43 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    first_step(t_stack **stack_a, t_stack **stack_b)
{
    int     size;
    int     i;
    int     push;

    i = 0;
    push = 0;
    size = ft_list_size(stack_a);
    while (size > 6 && i < size)
    {
        if ((*stack_a)->index < size / 2)
        {
            pb(stack_a, stack_b);
            push++;
        }
        else
            ra(stack_a);
        i++;
    }
    while (size - push > 3)
    {
        pb(stack_a, stack_b);
        push++;
    }
}

void    second_step(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *max_a;
    t_stack *temp_a;
    t_stack *temp_b;
    int     diff;

    max_a = max_index(stack_a);
    temp_a = *stack_a;
    temp_b = *stack_b;
    while (temp_b)
    {
        if (temp_b->index > max_a->index)
            temp_b->target_pos = min_index(stack_a)->pos;
        diff = max_a->index - temp_b->index;
        ft_tar_pos(temp_a, temp_b, &diff);
        temp_a = *stack_a;
        temp_b = temp_b->next;
    }
}

void    third_step(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp_b;
    int     size_a;
    int     size_b;
    int     aux_a;
    int     aux_b;

    temp_b = *stack_b;
    size_a = ft_list_size(stack_a);
    size_b = ft_list_size(stack_b);
    aux_a = ft_odd(size_a);
    aux_b = ft_odd(size_b);
    while (temp_b)
    {
        temp_b->cost_b = temp_b->pos - 1;
        if (temp_b->pos > aux_b)
            temp_b->cost_b = (size_b - temp_b->pos + 1) * -1;
        temp_b->cost_a = temp_b->target_pos - 1;
        if (temp_b->target_pos > aux_a)
            temp_b->cost_a = (size_a - temp_b->target_pos + 1) * -1;
        temp_b = temp_b->next;
    }
}

void    fourth_step(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest;

    cheapest = find_cheapest(stack_b);
    while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rrr(stack_a, stack_b);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
    while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
        rr(stack_a, stack_b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
    rotate_stack_a(stack_a, &(cheapest->cost_a));
    rotate_stack_b(stack_b, &(cheapest->cost_b));
	pa(stack_a, stack_b);
}

void    last_step(t_stack **stack_a)
{
    int	top;
	int	size;

	size = ft_list_size(stack_a);
	top = min_index(stack_a)->index;
	if(top <= size / 2)
	{
		while((*stack_a)->index != 1)
			ra(stack_a);
	}
	else
	{
		while((*stack_a)->index != 1)
			rra(stack_a);
	}
}