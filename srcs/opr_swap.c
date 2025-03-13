/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:13:40 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/13 13:45:55 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap top 2 elements
//2-define
//4-define new top (has 2 nodes only)
//2-detach & update
//2-reconnect to surrounding nodes (node b4 1st and node after 2nd)
//3-put in the right order
void	swap(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!stack || !stack->top)
		return ;
	if (stack->size < 2)
		return ;
	first_node = stack->top;
	second_node = first_node->next;
	if (stack->size == 2)
	{
		stack->top = second_node;
		return ;
	}
	first_node->next = second_node->next;
	second_node->prev = first_node->prev;
	first_node->prev->next = second_node;
	second_node->next->prev = first_node;
	second_node->next = first_node;
	first_node->prev = second_node;
	stack->top = second_node;
}

void	sa(t_stack *stack_a, bool checker)
{
	swap(stack_a);
	if (checker == true)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack_b, bool checker)
{
	swap(stack_b);
	if (checker == true)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, bool checker)
{
	swap(stack_a);
	swap(stack_b);
	if (checker == true)
		ft_putendl_fd("ss", 1);
}
