/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:50:36 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/14 09:59:16 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// use this instead of "../include/push_swap.h" because 
// we already add -I../include in our Makefile
// wont need to update too if you change the location of the header
// I../include in Makefile for this header
#include "push_swap.h"

// return 1 in int main instead of exit(1)
// quite equivalent but subtle differences :
// 	return 1 = readable, proper cleanup of local objects in main, graceful exit
// 	exit 1 = still reachable leaks, forceful and abrupt: 
// 				used only in non main functions or exceptional cases
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
