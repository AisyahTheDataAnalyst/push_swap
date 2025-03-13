/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:44:17 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/13 14:24:30 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_same_top(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	int	count_a;
	int	count_b;

	count_a = node->index;
	count_b = node->b_node->index;
	while (count_a > 0 && count_b > 0)
	{
		rr(stack_a, stack_b, true);
		count_a--;
		count_b--;
	}
	while (count_a-- > 0)
		ra(stack_a, true);
	while (count_b-- > 0)
		rb(stack_b, true);
	pb(stack_a, stack_b, true);
}

void	exec_top_bottom(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	int	count_a;
	int	count_b;

	count_a = node->index;
	stack_b->size = count_of_nodes(stack_b);
	count_b = stack_b->size - node->b_node->index;
	while (count_a-- > 0)
		ra(stack_a, true);
	while (count_b-- > 0)
		rrb(stack_b, true);
	pb(stack_a, stack_b, true);
}

void	exec_bottom_top(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	int	count_a;
	int	count_b;

	stack_a->size = count_of_nodes(stack_a);
	count_a = stack_a->size - node->index;
	count_b = node->b_node->index;
	while (count_a-- > 0)
		rra(stack_a, true);
	while (count_b-- > 0)
		rb(stack_b, true);
	pb(stack_a, stack_b, true);
}

void	exec_same_bottom(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	int	count_a;
	int	count_b;

	stack_a->size = count_of_nodes(stack_a);
	stack_b->size = count_of_nodes(stack_b);
	count_a = stack_a->size - node->index;
	count_b = stack_b->size - node->b_node->index;
	while (count_a > 0 && count_b > 0)
	{
		rrr(stack_a, stack_b, true);
		count_a--;
		count_b--;
	}
	while (count_a-- > 0)
		rra(stack_a, true);
	while (count_b-- > 0)
		rrb(stack_b, true);
	pb(stack_a, stack_b, true);
}
