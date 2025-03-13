/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:23:36 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/13 17:46:02 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*instructions;

	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a);
	if (!stack_a)
		return (1);
	first_stage(ac, av, stack_a);
	init_stack(&stack_b);
	if (!stack_b)
	{
		free_cdllist(stack_a);
		return (1);
	}
	instructions = get_next_line(STDIN_FILENO);
	while (instructions)
	{
		commands_input(stack_a, stack_b, instructions);
		free(instructions);
		instructions = get_next_line(STDIN_FILENO);
	}
	ending(stack_a, stack_b);
}

void	first_stage(int ac, char **av, t_stack *stack_a)
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
}

void	free_bonus(t_stack *stack_a, t_stack *stack_b)
{
	free_cdllist(stack_a);
	free_cdllist(stack_b);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	commands_input(t_stack *stack_a, t_stack *stack_b, char *instructions)
{
	if (ft_strncmp(instructions, "sa\n", 3) == 0)
		sa(stack_a, false);
	else if (ft_strncmp(instructions, "sb\n", 3) == 0)
		sb(stack_b, false);
	else if (ft_strncmp(instructions, "ss\n", 3) == 0)
		ss(stack_a, stack_b, false);
	else if (ft_strncmp(instructions, "ra\n", 3) == 0)
		ra(stack_a, false);
	else if (ft_strncmp(instructions, "rb\n", 3) == 0)
		rb(stack_b, false);
	else if (ft_strncmp(instructions, "rr\n", 3) == 0)
		rr(stack_a, stack_b, false);
	else if (ft_strncmp(instructions, "rra\n", 4) == 0)
		rra(stack_a, false);
	else if (ft_strncmp(instructions, "rrb\n", 4) == 0)
		rrb(stack_b, false);
	else if (ft_strncmp(instructions, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, false);
	else if (ft_strncmp(instructions, "pb\n", 3) == 0)
		pb(stack_a, stack_b, false);
	else if (ft_strncmp(instructions, "pa\n", 3) == 0)
		pa(stack_a, stack_b, false);
	else
		free_bonus(stack_a, stack_b);
}

void	ending(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) == true && count_of_nodes(stack_b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_cdllist(stack_a);
	free_cdllist(stack_b);
}
