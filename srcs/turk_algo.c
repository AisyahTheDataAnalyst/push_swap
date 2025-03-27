/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:53:37 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/14 12:54:23 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// aisyah you can do this
// just randomly push 2 nodes , so theres min and max of stack_b
// before pushing a to b, in every loop
// 		- node->index : check index each node of both a & b
//		- node->above_median : check median for each node of both a & b
//		- node->b_node : check which b node is the target for a node
//		- node->steps : check how many steps of a to target node b
void	turk_algo(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;

	pb(stack_a, stack_b, true);
	pb(stack_a, stack_b, true);
	size_a = count_of_nodes(stack_a);
	while (size_a-- > 0)
	{
		index_median(stack_a);
		index_median(stack_b);
		steps_calc(stack_a, stack_b);
		a_to_b(stack_a, stack_b);
	}
	b_to_a(stack_a, stack_b);
	index_median(stack_a);
	min_on_top(stack_a);
}

void	index_median(t_stack *stack)
{
	t_node	*curr;
	int		median;
	int		i;

	curr = stack->top;
	median = stack->size / 2;
	i = 0;
	while (1)
	{
		curr->index = i;
		if (i < median)
			curr->above_median = true;
		else
			curr->above_median = false;
		curr = curr->next;
		i++;
		if (curr == stack->top)
			break ;
	}
}

void	min_on_top(t_stack *stack_a)
{
	t_node	*min;

	min = find_smallest_node(stack_a);
	while (min != stack_a->top)
	{
		if (min->above_median == true)
			ra(stack_a, true);
		if (min->above_median == false)
			rra(stack_a, true);
	}
}
