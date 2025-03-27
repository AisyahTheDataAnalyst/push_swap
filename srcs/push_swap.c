/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:28:38 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/14 12:24:22 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// purpose : parsing input 
// = process of reading, validating, and preparing the input data 
//   (a list of numbers) so that it can be used by the program
// 3 sections = recieving input, transform to long&linked list, error-handling
void	process_input(int ac, char **av, t_stack *stack_a)
{
	char	**split;

	split = inputting(ac, av);
	if (filter_digit(split) == false)
	{
		free_split(split);
		error_exit(stack_a);
	}
	input_into_cdllist(split, stack_a);
	stack_a->size = count_of_nodes(stack_a);
	if (error_handling(stack_a) == false)
	{
		free_cdllist(stack_a);
		error_exit2("Error");
	}
	if (stack_a->size == 1 || is_sorted(stack_a) == true)
	{
		free_cdllist(stack_a);
		exit(0);
	}
}

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a, true);
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size == 4)
		sort_4(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_5(stack_a, stack_b);
	else
		turk_algo(stack_a, stack_b);
}
