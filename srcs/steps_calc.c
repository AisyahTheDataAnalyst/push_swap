/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:35:33 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/14 12:50:16 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// purpose : setting up the numbers for node->steps on all stack_a nodes
// 1 - bsteps = steps taken to get target node b to the top
// 2 - node->steps = steps taken to get node a to the stop + bsteps + push (1)
void	steps_calc(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		b_steps;

	node = stack_a->top;
	while (1)
	{
		node->b_node = set_target_b(node->num, stack_b);
		if (node->b_node->index < stack_b->size / 2)
			b_steps = node->b_node->index;
		else
			b_steps = stack_b->size - node->b_node->index;
		if (node->index < stack_a->size / 2)
			node->steps = node->index + b_steps + 1;
		else
			node->steps = (stack_a->size - node->index) + b_steps + 1;
		node = node->next;
		if (node == stack_a->top)
			break ;
	}
}

// purpose : searching for target node b to push a on top of it.
// target node b = closest smaller than a  
// compare either extreme situations: num > max or num < min
// compare if num is in between:  node > num > node_b->next
t_node	*set_target_b(long num, t_stack *stack_b)
{
	t_node	*node_b;
	t_node	*max;
	t_node	*min;

	if (!stack_b || !stack_b->top)
		return (NULL);
	max = find_biggest_node(stack_b);
	min = find_smallest_node(stack_b);
	node_b = stack_b->top;
	if (num > max->num)
		return (max);
	if (num < min->num)
		return (min->next);
	while (1)
	{
		if (num < node_b->num && num > node_b->next->num)
			return (node_b->next);
		node_b = node_b->next;
		if (node_b == stack_b->top)
			break ;
	}
	return (max);
}
