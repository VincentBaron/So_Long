/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by vbaron            #+#    #+#             */
/*   Updated: 2021/09/06 12:28:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_clean(t_general *mother)
{
	int	i;

	i = 0;
	while (mother->args.matrix[i])
	{
		if (mother->args.matrix[i])
			ft_free(mother->args.matrix[i]);
		i++;
	}
	if (mother->args.matrix)
		free(mother->args.matrix);
	clear_images(mother);
	if (mother->mlx.win)
		mlx_destroy_window(mother->mlx.ptr, mother->mlx.win);
	if (mother->mlx.ptr)
		mlx_destroy_display(mother->mlx.ptr);
	if (mother->mlx.ptr)
		free(mother->mlx.ptr);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_general *mother)
{
	mother->gps.event = 1;
	if (keycode == UP)
		mother->gps.move.y = -1;
	else if (keycode == DOWN)
		mother->gps.move.y = 1;
	else if (keycode == LEFT)
		mother->gps.move.x = -1;
	else if (keycode == RIGHT)
		mother->gps.move.x = 1;
	else if (keycode == ESC)
		ft_clean(mother);
	mother->gps.event = 1;
	return (0);
}

int	key_release(int keycode, t_general *mother)
{
	mother->gps.event = 0;
	mother->gps.move.x = 0;
	mother->gps.move.y = 0;
	(void)keycode;
	return (0);
}

int	events_list(t_general *mother)
{
	check_collectibles(mother);
	if (mother->exit == 0)
		final(mother);
	else
	{
		if (mother->gps.event == 1)
			new_map(mother);
		mother->gps.event = 0;
	}
	return (0);
}

void	game_start(t_general *mother)
{
	mother->gps.move.x = 0;
	mother->gps.event = 0;
	mother->gps.move.y = 0;
	mother->move = 0;
	mother->args.R[0] = 5000;
	mother->args.R[1] = 5000;
	mother->mlx.ptr = mlx_init();
	if (!mother->mlx.ptr)
		ft_putstr_fd("Error initialising mlx", 1);
	mother->mlx.win = mlx_new_window(mother->mlx.ptr,
			mother->args.R[0], mother->args.R[1], "So_long");
	if (!mother->mlx.win)
		ft_putstr_fd("Error creating window", 1);
	load_textures(mother);
	draw_map(mother);
	mlx_hook(mother->mlx.win, KEY_PRESS, 1L << 0, &key_press, mother);
	mlx_hook(mother->mlx.win, 33, (1L << 17), ft_clean, mother);
	mlx_hook(mother->mlx.win, KEY_RELEASE, 1L << 1, &key_release, mother);
	mlx_loop_hook(mother->mlx.ptr, &events_list, mother);
	mlx_loop(mother->mlx.ptr);
}
