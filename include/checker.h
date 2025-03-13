/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:58:14 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/13 15:22:32 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdio.h> // delete soon

void	free_bonus(t_stack *a, t_stack *stack_b);
void	commands_input(t_stack *stack_a, t_stack *stack_b, char *instructions);
void	ending(t_stack *stack_a, t_stack *stack_b);
void	first_stage(int ac, char **av, t_stack *stack_a);

#endif