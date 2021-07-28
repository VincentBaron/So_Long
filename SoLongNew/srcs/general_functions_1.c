/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_functions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:42:53 by vbaron            #+#    #+#             */
/*   Updated: 2020/10/16 17:20:40 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_map(t_input *args)
{
	char	*dup;
	int		size;
	int		i;

	i = 0;
	while ((args->line)[i] == ' ' || (args->line)[i] == '1')
	{
		if (args->line[i] == '1')
		{
			size = ft_strlen(args->line);
			if (!(dup = malloc(sizeof(char) * (size + 2))))
				return;
			i = 0;
			while (i < size)
			{
				dup[i] = args->line[i];
				i++;
			}
			dup[i] = 'x';
			i++;
			dup[i] = '\0';
			args->map = ft_strjoin(args->map, dup);
			break;
		}
		i++;
	}
}