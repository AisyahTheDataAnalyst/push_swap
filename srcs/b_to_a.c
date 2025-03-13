/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:09:48 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/13 14:23:00 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// must have another variable to decrement instead of stack_b->size--, 
// stack_b->size is decrementing in the loop, it leads to incorrect behaviour
// if we dont seperate using another counter to do the countdown.
// so in this case, we use count_of_nodes instead. 
void	b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	size_b;

	size_b = count_of_nodes(stack_b);
	while (size_b-- > 0)
		pa(stack_a, stack_b, true);
}
