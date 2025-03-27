/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_into_cdllist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:03:23 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/14 11:06:38 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// purpose : transform type of data and type of data structure 
// data - from str to long
// data structure - from array to cdllist
void	input_into_cdllist(char **split, t_stack *stack_a)
{
	long	nbr;
	int		i;

	i = 0;
	while (split[i])
	{
		nbr = ft_atol(split[i], stack_a);
		insert_end(nbr, stack_a);
		i++;
	}
	free_split(split);
}

long	ft_atol(char *split, t_stack *stack_a)
{
	long	res;
	int		i;
	long	sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((split[i] >= 9 && split[i] <= 13) || split[i] == 32)
		i++;
	if (split[i] == '+' || split[i] == '-')
	{
		if (split[i] == '-')
			sign = -1;
		i++;
		if (split[i] == '+' || split[i] == '-')
			error_exit(stack_a);
	}
	while (split[i] >= '0' && split[i] <= '9')
	{
		res = res * 10 + (split[i] - 48);
		i++;
	}
	return (res * sign);
}

void	insert_end(long nbr, t_stack *stack_a)
{
	t_node	*new_node;
	t_node	*top_node;
	t_node	*last_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->num = nbr;
	if (!stack_a->top)
	{
		stack_a->top = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		top_node = stack_a->top;
		last_node = top_node->prev;
		last_node->next = new_node;
		new_node->prev = last_node;
		new_node->next = top_node;
		top_node->prev = new_node;
	}
}
