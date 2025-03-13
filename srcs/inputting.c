/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimokhta <aimokhta@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:54:03 by aimokhta          #+#    #+#             */
/*   Updated: 2025/03/12 14:14:07 by aimokhta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**inputting(int ac, char **av)
{
	char	**split;
	char	*joined;

	if (ac == 1)
		exit(1);
	if (ac == 2 && !av[1][0])
		error_exit2("Error");
	joined = str_join(av);
	if (!joined)
		return (NULL);
	split = ft_split(joined, ' ');
	free(joined);
	return (split);
}

char	*str_join(char **av)
{
	char	*joined;
	char	*temp;
	char	*str;
	int		i;

	if (!av || !(*av) || !av[1][0])
		return (NULL);
	i = 1;
	joined = ft_strdup("");
	while (av[i])
	{
		temp = ft_strjoin(av[i], " ");
		str = joined;
		joined = ft_strjoin(str, temp);
		free (temp);
		free (str);
		i++;
	}
	return (joined);
}
