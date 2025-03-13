/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:15:51 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/12 13:00:13 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = minimum_steps(stack_a);
	if (node->index < stack_a->size / 2)
	{
		if (node->b_node->index < stack_b->size / 2)
			exec_same_top(node, stack_a, stack_b);
		else
			exec_top_bottom(node, stack_a, stack_b);
	}
	else
	{
		if (node->b_node->index < stack_b->size / 2)
			exec_bottom_top(node, stack_a, stack_b);
		else
			exec_same_bottom(node, stack_a, stack_b);
	}
}

t_node	*minimum_steps(t_stack *stack_a)
{
	t_node	*init;
	t_node	*min;
	t_node	*iterate;

	init = stack_a->top;
	min = stack_a->top;
	iterate = init->next;
	while (iterate != init)
	{
		if (iterate->steps < min->steps)
			min = iterate;
		iterate = iterate->next;
	}
	return (min);
}
