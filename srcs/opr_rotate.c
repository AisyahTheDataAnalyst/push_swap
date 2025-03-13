/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:36:54 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/13 13:45:18 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts up all elements by 1
//1-define
//1-readjust stack pointer
void	rotate(t_stack *stack)
{
	t_node	*first_node;

	if (!stack || !stack->top)
		return ;
	if (stack->size < 2)
		return ;
	first_node = stack->top;
	stack->top = first_node->next;
}

void	ra(t_stack *stack_a, bool checker)
{
	rotate(stack_a);
	if (checker == true)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack_b, bool checker)
{
	rotate(stack_b);
	if (checker == true)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b, bool checker)
{
	rotate(stack_a);
	rotate(stack_b);
	if (checker == true)
		ft_putendl_fd("rr", 1);
}
