/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:17:10 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/14 11:43:18 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	error_handling(t_stack *stack_a)
{
	if (range_of_int(stack_a) == false)
		return (false);
	if (no_dupes(stack_a) == false)
		return (false);
	return (true);
}

bool	range_of_int(t_stack *stack_a)
{
	t_node	*node;

	node = stack_a->top;
	while (1)
	{
		if (node->num < INT_MIN || node->num > INT_MAX)
			return (false);
		node = node->next;
		if (node == stack_a->top)
			break ;
	}
	return (true);
}

bool	no_dupes(t_stack *stack_a)
{
	t_node	*target;
	t_node	*iterate;

	target = stack_a->top;
	while (target->next != stack_a->top)
	{
		iterate = target->next;
		while (iterate != stack_a->top)
		{
			if (iterate->num == target->num)
				return (false);
			iterate = iterate->next;
		}
		target = target->next;
	}
	return (true);
}

bool	is_sorted(t_stack *stack_a)
{
	t_node	*node;
	int		unsorted_flag;

	node = stack_a->top;
	unsorted_flag = 0;
	while (unsorted_flag == 0)
	{
		if (node->next != stack_a->top)
			if (node->num > node->next->num)
				unsorted_flag = 1;
		node = node->next;
		if (node == stack_a->top)
			break ;
	}
	if (unsorted_flag == 1)
		return (false);
	return (true);
}

bool	filter_digit(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		if (split[i][j] == '\0')
			return (false);
		while (split[i][j])
		{
			if (split[i][j] == '-' || split[i][j] == '+')
				j++;
			if (split[i][j] == '-' || split[i][j] == '+')
				return (false);
			if (split[i][j] == '\0' || split[i][j] == 32 || split[i][j] == '\t')
				return (false);
			while (ft_isdigit(split[i][j]) && split[i][j])
				j++;
			if (!ft_isdigit(split[i][j]) && split[i][j])
				return (false);
		}
		i++;
	}
	return (true);
}
