/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:37:28 by vincentbaro       #+#    #+#             */
/*   Updated: 2021/09/06 11:31:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_textures(t_general *mother)
{
	mother->args.player.image = mlx_xpm_file_to_image(mother->mlx.ptr,
			"./textures/player.xpm",
			&(mother->args.player.width), &(mother->args.player.height));
	mother->args.floor.image = mlx_xpm_file_to_image(mother->mlx.ptr,
			"./textures/grass.xpm",
			&(mother->args.floor.width), &(mother->args.floor.height));
	mother->args.wall.image = mlx_xpm_file_to_image(mother->mlx.ptr,
			"./textures/wall.xpm",
			&(mother->args.wall.width), &(mother->args.wall.height));
	mother->args.coins1.image = mlx_xpm_file_to_image(mother->mlx.ptr,
			"./textures/coin.xpm",
			&(mother->args.coins1.width), &(mother->args.coins1.height));
	mother->args.exit.image = mlx_xpm_file_to_image(mother->mlx.ptr,
			"./textures/exit.xpm",
			&(mother->args.exit.width), &(mother->args.exit.height));
}
