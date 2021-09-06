/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:13:03 by user42            #+#    #+#             */
/*   Updated: 2021/09/06 12:26:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_display(int e)
{
	if (e == 1)
		ft_putstr_fd("Error\n1: Map is unvalid\n", 1);
	if (e == 3)
		ft_putstr_fd("Error\n3: Malloc Error\n", 1);
	if (e == 4)
		ft_putstr_fd("Error\n4: Too many players\n", 1);
	if (e == 5)
		ft_putstr_fd("Error\n5: Could not create bmp image\n", 1);
}

void	error(t_general *mother, int e)
{
	int	i;

	if (e == 2)
	{
		ft_putstr_fd("Error\n2: Arguments invalid\n", 1);
		exit(1);
	}
	i = 0;
	while (mother->args.matrix[i])
	{
		if (mother->args.matrix[i])
			ft_free(mother->args.matrix[i]);
		i++;
	}
	if (mother->args.matrix)
		free(mother->args.matrix);
	if (mother->args.map)
		free(mother->args.map);
	error_display(e);
	exit(1);
}

void	clear_images(t_general *mother)
{
	if (mother->args.wall.image)
		mlx_destroy_image(mother->mlx.ptr, (mother->args.wall.image));
	if (mother->args.floor.image)
		mlx_destroy_image(mother->mlx.ptr, mother->args.floor.image);
	if (mother->args.coins1.image)
		mlx_destroy_image(mother->mlx.ptr, mother->args.coins1.image);
	if (mother->args.exit.image)
		mlx_destroy_image(mother->mlx.ptr, mother->args.exit.image);
	if (mother->args.player.image)
		mlx_destroy_image(mother->mlx.ptr, mother->args.player.image);
}
