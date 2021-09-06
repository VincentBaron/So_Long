/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:22:49 by user42            #+#    #+#             */
/*   Updated: 2021/09/06 12:24:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	display_image(t_general *mother, void *img)
{
	mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, img,
		mother->args.wall.width * mother->map.track_y,
		mother->args.wall.height * mother->map.track_x);
}

void	check_display(t_general *mother, char pos)
{
	if (pos == '1')
		display_image(mother, mother->args.wall.image);
	if (pos == '0')
		display_image(mother, mother->args.floor.image);
	if (pos == 'P')
	{
		display_image(mother, mother->args.floor.image);
		display_image(mother, mother->args.player.image);
	}
	if (pos == 'C')
	{
		display_image(mother, mother->args.floor.image);
		display_image(mother, mother->args.coins1.image);
	}
	if (pos == 'E')
	{
		display_image(mother, mother->args.floor.image);
		display_image(mother, mother->args.exit.image);
	}
}

void	draw_map(t_general *mother)
{
	char	*move_str;
	char	pos;

	move_str = ft_itoa(mother->move);
	mother->move++;
	mother->map.track_x = 0;
	while (mother->args.matrix[mother->map.track_x])
	{
		mother->map.track_y = 0;
		while (mother->args.matrix[mother->map.track_x][mother->map.track_y])
		{
			pos = mother->args.matrix[mother->map.track_x][mother->map.track_y];
			check_display(mother, pos);
			mother->map.track_y++;
		}
		mother->map.track_x++;
	}
	ft_free(move_str);
}
