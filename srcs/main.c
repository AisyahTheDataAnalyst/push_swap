/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:50:36 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/13 16:16:50 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// use this instead of "../include/push_swap.h" because 
// we already add -I../include in our Makefile
// wont need to update too if you change the location of the header
// I../include in Makefile for this header
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a);
	if (!stack_a)
		return (1);
	process_input(ac, av, stack_a);
	init_stack(&stack_b);
	if (!stack_b)
	{
		free_cdllist(stack_a);
		return (1);
	}
	sorting(stack_a, stack_b);
	free_cdllist(stack_b);
	free_cdllist(stack_a);
	return (0);
}
