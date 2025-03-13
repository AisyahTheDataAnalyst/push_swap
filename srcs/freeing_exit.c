/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:40:50 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/12 13:00:35 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *stack_a)
{
	ft_putendl_fd("Error", 2);
	if (stack_a)
		free(stack_a);
	exit(1);
}

void	error_exit2(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

// NULL at the end so that stack in int main is also NULL
// no need to set stack->top = NULL and stack->size = 0, segfault!
// 		because youre trying to access them after you free the stack already
//		ater free(stack), stack becomes a dangling pointer
//		Dereferencing it (stack->top or stack->size) accesses invalid memory,
//		causing a segfault.
void	free_cdllist(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	if (!stack)
		return ;
	if (!stack->top)
	{
		free(stack);
		return ;
	}
	node = (stack)->top;
	while (1)
	{
		temp = node;
		node = node->next;
		free(temp);
		if (node == (stack)->top)
			break ;
	}
	free(stack);
}

// No need to split = NULL at the end, this is just a local variable, 
// so its unnecessary 
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
