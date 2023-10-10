/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:59:52 by agvincen          #+#    #+#             */
/*   Updated: 2023/10/10 15:05:16 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* void	ft_leaks(void)
{
	system("leaks -q push_swap");
}
	atexit(ft_leaks); */

void	ft_exit(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("Error\n");
	if (stack_a)
		ft_clear(stack_a);
	if (stack_b)
		ft_clear(stack_b);
	exit(1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (ft_sorted(stack_a))
		return ;
	if (i == 1)
		return ;
	else if (i == 2)
		sa(stack_a);
	else if (i == 3)
		ft_three(stack_a);
	else
		ft_many(stack_a, stack_b);
}

void	ft_control(char **argv, t_stack **stack_a, t_stack **stack_b, int argc)
{
	int			i;
	long int	num;
	char		**array;

	i = 1;
	if (argc == 2)
	{	
		array = ft_split(argv[1], ' ');
		argv = array;
		i = 0;
	}
	while (argv[i])
	{
		if (is_integer(argv[i]) == 0)
			ft_exit(stack_a, stack_b);
		num = ft_atoi(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			ft_exit(stack_a, stack_b);
		*stack_a = ft_stack_new(*stack_a, num);
		if (is_duplicate(*stack_a, num) > 1)
			ft_exit(stack_a, stack_b);
		i++;
	}
	if (argc == 2)
		free_array(argv);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	ft_control(argv, &stack_a, &stack_b, argc);
	ft_index(stack_a);
	ft_pos(&stack_a);
	push_swap(&stack_a, &stack_b, ft_list_size(&stack_a));
	ft_clear(&stack_a);
	ft_clear(&stack_b);
	return (0);
}
