/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:00:35 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/02 14:00:35 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!(*stack))
		return ;
	(*stack)->top = NULL;
	(*stack)->size = 0;
}

int	count_of_nodes(t_stack *stack)
{
	int		count;
	t_node	*node;

	if (!stack || !stack->top)
		return (0);
	count = 0;
	node = stack->top;
	while (1)
	{
		count++;
		node = node->next;
		if (node == stack->top)
			break ;
	}
	return (count);
}

t_node	*find_biggest_node(t_stack *stack)
{
	t_node	*init;
	t_node	*biggest;
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	init = stack->top;
	biggest = stack->top;
	node = init->next;
	while (node != init)
	{
		if (node->num > biggest->num)
			biggest = node;
		node = node->next;
	}
	return (biggest);
}

t_node	*find_smallest_node(t_stack *stack)
{
	t_node	*smallest;
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	smallest = node;
	node = node->next;
	while (1)
	{
		if (node->num < smallest->num)
			smallest = node;
		node = node->next;
		if (node == stack->top)
			break ;
	}
	return (smallest);
}
