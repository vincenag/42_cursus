/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:00:15 by agvincen          #+#    #+#             */
/*   Updated: 2023/09/30 17:04:45 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_stack_new(t_stack *stack, int value, int pos);
void				ft_index(t_stack *stack);
void				ft_exit(t_stack **stack_a, t_stack **stack_b, char **argv, int argc);
int					is_integer(char *str);
int					is_duplicate(t_stack *stack, int num);
void				ft_clear(t_stack **stack);
void				free_array(char **arr);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
int					ft_sorted(t_stack **stack);
t_stack				*stack_bottom(t_stack *stack);
void				ft_three(t_stack **stack);
int					ft_list_size(t_stack **stack);
int 				ft_odd(int  size);
void				ft_many(t_stack **stack_a, t_stack **stack_b);
void    			first_step(t_stack **stack_a, t_stack **stack_b);
t_stack				*max_index(t_stack **stack);
t_stack				*min_index(t_stack **stack);
void    			second_step(t_stack **stack_a, t_stack **stack_b);
void    			third_step(t_stack **stack_a, t_stack **stack_b);
void    			fourth_step(t_stack **stack_a, t_stack **stack_b);
void				ft_tar_pos(t_stack *temp_a, t_stack *temp_b, int *diff);
t_stack				*find_cheapest(t_stack **stack_b);
void 				rotate_stack_a(t_stack **stack_a, int *cost_a);
void				last_step(t_stack **stack_a);
void 				rotate_stack_b(t_stack **stack_b, int *cost_b);

#endif