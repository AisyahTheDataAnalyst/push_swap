/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:37:43 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/13 13:40:49 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift down all elements by 1
void	reverse_rotate(t_stack *stack)
{
	t_node	*last_node;

	if (!stack || !stack->top)
		return ;
	if (stack->size < 2)
		return ;
	last_node = stack->top->prev;
	stack->top = last_node;
}

void	rra(t_stack *stack_a, bool checker)
{
	reverse_rotate(stack_a);
	if (checker == true)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack_b, bool checker)
{
	reverse_rotate(stack_b);
	if (checker == true)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, bool checker)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (checker == true)
		ft_putendl_fd("rrr", 1);
}
