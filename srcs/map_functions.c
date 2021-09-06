/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:31:48 by vbaron            #+#    #+#             */
/*   Updated: 2021/09/06 12:23:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	redraw_pos(t_general *mother, t_coor old_pos, int id)
{
	if (id == 1)
		mother->gps.pos.y -= 1;
	if (id == 2)
		mother->gps.pos.y += 1;
	if (id == 3)
		mother->gps.pos.x -= 1;
	if (id == 4)
		mother->gps.pos.x += 1;
	mother->args.matrix[(int)mother->gps.pos.y]
	[(int)mother->gps.pos.x] = 'P';
	mother->args.matrix[(int)old_pos.y][(int)old_pos.x] = '0';
}

void	redefine_pos(t_general *mother)
{
	t_coor	old_pos;
	char	*block;

	if (mother->collectibles != 0)
		block = ft_strdup("1E");
	else
		block = ft_strdup("1");
	old_pos.y = mother->gps.pos.y;
	old_pos.x = mother->gps.pos.x;
	if (mother->gps.move.y == -1 && check_charset(mother->args.matrix[(int)
				(mother->gps.pos.y - 1)][(int)mother->gps.pos.x], block) == -1)
		redraw_pos(mother, old_pos, 1);
	else if (mother->gps.move.y == 1 && check_charset(mother->args.matrix[(int)
				(mother->gps.pos.y + 1)][(int)mother->gps.pos.x], block) == -1)
		redraw_pos(mother, old_pos, 2);
	else if (mother->gps.move.x == -1 && check_charset(mother->args.matrix[(int)
				mother->gps.pos.y][(int)(mother->gps.pos.x - 1)], block) == -1)
		redraw_pos(mother, old_pos, 3);
	else if (mother->gps.move.x == +1 && check_charset(mother->args.matrix[(int)
				mother->gps.pos.y][(int)(mother->gps.pos.x + 1)], block) == -1)
		redraw_pos(mother, old_pos, 4);
	free(block);
}

void	check_collectibles(t_general *mother)
{
	int	i;
	int	j;

	mother->collectibles = 0;
	mother->exit = 0;
	i = 0;
	while (mother->args.matrix[i])
	{
		j = 0;
		while (mother->args.matrix[i][j])
		{
			if (mother->args.matrix[i][j] == 'C')
				mother->collectibles++;
			if (mother->args.matrix[i][j] == 'E')
				mother->exit++;
			j++;
		}
		i++;
	}
}

void	final(t_general *mother)
{
	mother->map.track_x = 0;
	while (mother->args.matrix[mother->map.track_x])
	{
		mother->map.track_y = 0;
		while (mother->args.matrix[mother->map.track_x][mother->map.track_y])
		{
			mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win,
				mother->args.floor.image,
				mother->map.track_y * 64, mother->map.track_x * 64);
			mother->map.track_y++;
		}
		mother->map.track_x++;
	}
}

int	new_map(t_general *mother)
{
	redefine_pos(mother);
	draw_map(mother);
	return (0);
}
