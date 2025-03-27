/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:14:41 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/10 15:14:41 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack_a)
{
	t_node	*biggest;
	t_node	*node;

	biggest = find_biggest_node(stack_a);
	node = stack_a->top;
	if (node == biggest)
	{
		ra(stack_a, true);
		node = node->prev->prev;
	}
	else if (node->next == biggest)
	{
		rra(stack_a, true);
		node = node->prev;
	}
	if (node->num > node->next->num)
		sa(stack_a, true);
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest;
	t_node	*node;

	index_median(stack_a);
	smallest = find_smallest_node(stack_a);
	node = stack_a->top;
	while (smallest != stack_a->top && smallest->above_median == true)
		ra(stack_a, true);
	while (smallest != stack_a->top && smallest->above_median == false)
		rra(stack_a, true);
	if (is_sorted(stack_a) == false)
	{
		pb(stack_a, stack_b, true);
		sort_3(stack_a);
		pa(stack_a, stack_b, true);
	}
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest;
	t_node	*node;

	index_median(stack_a);
	smallest = find_smallest_node(stack_a);
	node = stack_a->top;
	while (smallest != stack_a->top && smallest->above_median == true)
		ra(stack_a, true);
	while (smallest != stack_a->top && smallest->above_median == false)
		rra(stack_a, true);
	if (is_sorted(stack_a) == false)
	{
		pb(stack_a, stack_b, true);
		sort_4(stack_a, stack_b);
		pa(stack_a, stack_b, true);
	}
}
