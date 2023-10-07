/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 01:06:12 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/28 01:26:44 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate_stack_a(t_stack **stack_a, int *cost_a) 
{
    while (*cost_a > 0) 
    {
        ra(stack_a);
        (*cost_a)--;
    }
    while (*cost_a < 0) 
    {
        rra(stack_a);
        (*cost_a)++;
    }
}

void rotate_stack_b(t_stack **stack_b, int *cost_b) 
{
    while (*cost_b > 0) 
    {
        rb(stack_b);
        (*cost_b)--;
    }
    while (*cost_b < 0) 
    {
        rrb(stack_b);
        (*cost_b)++;
    }
}
