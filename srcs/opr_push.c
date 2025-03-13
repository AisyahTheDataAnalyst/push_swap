/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:36:43 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/13 13:39:31 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack_src, t_stack *stack_dest)
{
	t_node	*top_node;

	if (!stack_src || !stack_src->top)
		return ;
	top_node = stack_src->top;
	push_detach_top(stack_src, top_node);
	push_attach_top(stack_dest, top_node);
}

void	push_detach_top(t_stack *stack_src, t_node *top_node)
{
	t_node	*second_node;
	t_node	*last_node;	

	if (!stack_src || !top_node)
		return ;
	if (top_node->next == top_node)
	{
		stack_src->top = NULL;
		return ;
	}
	second_node = top_node->next;
	last_node = top_node->prev;
	second_node->prev = last_node;
	last_node->next = second_node;
	stack_src->top = second_node;
}

void	push_attach_top(t_stack *stack_dest, t_node *top_node)
{
	t_node	*top_node_dest;

	if (!stack_dest || !top_node)
		return ;
	if (stack_dest->top == NULL)
	{
		top_node->next = top_node;
		top_node->prev = top_node;
		stack_dest->top = top_node;
		return ;
	}	
	top_node_dest = stack_dest->top;
	top_node->next = top_node_dest;
	top_node->prev = top_node_dest->prev;
	top_node_dest->prev->next = top_node;
	top_node_dest->prev = top_node;
	stack_dest->top = top_node;
}

void	pa(t_stack *stack_a, t_stack *stack_b, bool checker)
{
	push(stack_b, stack_a);
	if (checker == true)
		ft_putendl_fd("pa", 1);
	stack_a->size++;
	stack_b->size--;
}

void	pb(t_stack *stack_a, t_stack *stack_b, bool checker)
{
	push(stack_a, stack_b);
	if (checker == true)
		ft_putendl_fd("pb", 1);
	stack_a->size--;
	stack_b->size++;
}
