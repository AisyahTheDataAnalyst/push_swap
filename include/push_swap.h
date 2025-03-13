/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:07:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/13 17:55:50 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h> //INT_MIN, INT_MAX
# include <stdlib.h> //malloc
# include <stdbool.h> //bool

typedef struct Nodes
{
	long			num;
	struct Nodes	*next;
	struct Nodes	*prev;
	struct Nodes	*b_node;
	int				steps;
	int				index;
	bool			above_median;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}			t_stack;

// opr_swap.c
void	swap(t_stack *stack);
void	sa(t_stack *stack_a, bool checker);
void	sb(t_stack *stack_b, bool checker);
void	ss(t_stack *stack_a, t_stack *stack_b, bool checker);

// opr_rotate.c
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a, bool checker);
void	rb(t_stack *stack_b, bool checker);
void	rr(t_stack *stack_a, t_stack *stack_b, bool checker);

// opr_reverse_rotate.c
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *stack_a, bool checker);
void	rrb(t_stack *stack_b, bool checker);
void	rrr(t_stack *stack_a, t_stack *stack_b, bool checker);

// opr_push.c
void	push(t_stack *stack_src, t_stack *stack_dest);
void	push_detach_top(t_stack *stack_src, t_node *top_node);
void	push_attach_top(t_stack *stack_dest, t_node *top_node);
void	pa(t_stack *stack_a, t_stack *stack_b, bool checker);
void	pb(t_stack *stack_a, t_stack *stack_b, bool checker);

// push_swap.c
void	process_input(int ac, char **av, t_stack *stack_a);
void	sorting(t_stack *stack_a, t_stack *stack_b);

// inputting.c
char	**inputting(int ac, char **av);
char	*str_join(char **av);

// input_into_cdllist.c
void	input_into_cdllist(char **split, t_stack *stack_a);
long	ft_atol(char *split, t_stack *stack_a);
void	insert_end(long nbr, t_stack *stack_a);

// error_handling.c
bool	error_handling(t_stack *stack_a);
bool	range_of_int(t_stack *stack_a);
bool	no_dupes(t_stack *stack_a);
bool	is_sorted(t_stack *stack_a);
bool	filter_digit(char **split);

// sort_small.c
void	sort_3(t_stack *stack_a);
void	sort_4(t_stack *stack_a, t_stack *stack_b);
void	sort_5(t_stack *stack_a, t_stack *stack_b);

// utils.c
void	init_stack(t_stack **stack);
int		count_of_nodes(t_stack *stack);
t_node	*find_biggest_node(t_stack *stack);
t_node	*find_smallest_node(t_stack *stack);

// freeing.c
void	error_exit(t_stack *stack_a);
void	error_exit2(char *message);
void	free_split(char **split);
void	free_cdllist(t_stack *stack);

// turk_algo.c
void	turk_algo(t_stack *stack_a, t_stack *stack_b);
void	index_median(t_stack *stack);
void	min_on_top(t_stack *stack_a);

// steps_calc.c
void	steps_calc(t_stack *stack_a, t_stack *stack_b);
t_node	*set_target_b(long num, t_stack *stack_b);

// a_to_b.c
void	a_to_b(t_stack *stack_a, t_stack *stack_b);
t_node	*minimum_steps(t_stack *stack_a);

// executions.c
void	exec_same_top(t_node *node, t_stack *stack_a, t_stack *stack_b);
void	exec_top_bottom(t_node *node, t_stack *stack_a, t_stack *stack_b);
void	exec_bottom_top(t_node *node, t_stack *stack_a, t_stack *stack_b);
void	exec_same_bottom(t_node *node, t_stack *stack_a, t_stack *stack_b);

//b_to_a.c
void	b_to_a(t_stack *stack_a, t_stack *stack_b);

#endif