/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:37:28 by vincentbaro       #+#    #+#             */
/*   Updated: 2021/07/25 15:15:07 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void load_textures(t_general *mother)
{
    int text_width;
    int text_height;

    text_width = 64;
    text_height = 64;

    mother->args.player = mlx_xpm_file_to_image(mother->mlx.ptr, "./textures/player.xpm", &(text_width), &(text_height));
    mother->args.floor = mlx_xpm_file_to_image(mother->mlx.ptr, "./textures/grass.xpm", &(text_width), &(text_height));
    mother->args.wall = mlx_xpm_file_to_image(mother->mlx.ptr, "./textures/wall.xpm", &(text_width), &(text_height));
    mother->args.coins1 = mlx_xpm_file_to_image(mother->mlx.ptr, "./textures/coin.xpm", &(text_width), &(text_height));
    mother->args.coins2 = mlx_xpm_file_to_image(mother->mlx.ptr, "./textures/coin2.xpm", &(text_width), &(text_height));
    mother->args.coins3 = mlx_xpm_file_to_image(mother->mlx.ptr, "./textures/coin3.xpm", &(text_width), &(text_height));
    mother->args.coins4 = mlx_xpm_file_to_image(mother->mlx.ptr, "./textures/coin4.xpm", &(text_width), &(text_height));
    mother->args.coins5 = mlx_xpm_file_to_image(mother->mlx.ptr, "./textures/coin5.xpm", &(text_width), &(text_height));
    mother->args.ennemy = mlx_xpm_file_to_image(mother->mlx.ptr, "./textures/bomb.xpm", &(text_width), &(text_height));
    mother->args.exit = mlx_xpm_file_to_image(mother->mlx.ptr, "./textures/exit.xpm", &(text_width), &(text_height));
}