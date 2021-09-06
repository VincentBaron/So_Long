/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:02:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/09/06 12:18:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_spaces(t_general *mother, int i, int f)
{
	if (i - 1 < 0 || f - 1 < 0
		|| (f + 1 == (int)ft_strlen(mother->args.matrix[i])))
		return (-1);
	if (check_charset(mother->args.matrix[i - 1][f], "01PEC") == -1
		|| check_charset(mother->args.matrix[i + 1][f], "01PEC") == -1
		|| check_charset(mother->args.matrix[i][f - 1], "01PEC") == -1
		|| check_charset(mother->args.matrix[i][f + 1], "01PEC") == -1)
		return (-1);
	return (0);
}

void	check_elems(t_general *mother, int i, int f)
{
	if (check_charset(mother->args.matrix[i][f], "10PCE") == -1)
		error(mother, 1);
	if (mother->args.matrix[i][f] == 'P')
	{
		mother->map.player_count++;
		if (mother->map.player_count > 1)
			mother->args.matrix[i][f] = '0';
	}
	if (mother->args.matrix[i][f] == 'C')
		mother->map.sprite_count++;
	if (mother->args.matrix[i][f] == 'E')
		mother->map.exit_count++;
	if (mother->args.matrix[i][f] == '0')
		if (check_spaces(mother, i, f))
			error(mother, 1);
}

void	check_map(t_general *mother)
{
	int	i;
	int	f;

	mother->map.player_count = 0;
	mother->map.sprite_count = 0;
	mother->map.exit_count = 0;
	i = 0;
	while (mother->args.matrix[i])
	{
		f = 0;
		while (mother->args.matrix[i][f])
		{
			check_elems(mother, i, f);
			f++;
		}
		if (i == 0)
			mother->map.map_length = f;
		else if (f != mother->map.map_length)
			error(mother, 1);
		i++;
	}
	if (mother->map.exit_count == 0 || mother->map.player_count == 0
		|| mother->map.sprite_count == 0)
		error(mother, 1);
}

int	map_parsing(t_input *args, t_general *mother)
{
	int	res;

	args->index = "1RNSWEXFC";
	(args->map) = ft_strdup("");
	res = get_next_line(args->fd, &(args->line));
	while (res != 0)
	{
		if (res == -1)
			return (-1);
		args->tracker = 0;
		while (args->line[args->tracker] == ' ')
			args->tracker++;
		args->index_i = check_charset(args->line[args->tracker], args->index);
		if (args->index_i == 0)
			create_map(args);
		ft_free(args->line);
		res = get_next_line(args->fd, &(args->line));
	}
	create_map(args);
	free(args->line);
	args->matrix = ft_split(args->map, "x");
	check_map(mother);
	ft_free(args->map);
	return (1);
}
