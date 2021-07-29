/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by vbaron            #+#    #+#             */
/*   Updated: 2021/07/29 21:27:10 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char *draw_pixel(t_general *mother, int x, int y)
{
     char *dest;

     dest = (mother->mlx.img_map.addr + x * (mother->mlx.img_map.bpp / 8) + y * mother->mlx.img_map.size_line);
     *(unsigned int *)dest = mother->mlx.img_map.color;
     return (dest);
}

void clear_images(t_general *mother)
{
     int i;

     i = 0;
     while (mother->args.matrix[i])
     {
          ft_free(mother->args.matrix[i]);
          i++;
     }

     mlx_destroy_image(mother->mlx.ptr, mother->args.wall);
     mlx_destroy_image(mother->mlx.ptr, mother->args.floor);
     mlx_destroy_image(mother->mlx.ptr, mother->args.coins1);
     mlx_destroy_image(mother->mlx.ptr, mother->args.exit);
     mlx_destroy_image(mother->mlx.ptr, mother->args.player);
     // free(mother->args.matrix);
     // free(mother->args.map);
     // free(mother->args.line);
     // free(mother->args.index);
}

int key_press(int keycode, t_general *mother)
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
     {
          clear_images(mother);
          mlx_destroy_window(mother->mlx.ptr, mother->mlx.win);
          exit(1);
     }
     mother->gps.event = 1;
     return (0);
}

int key_release(int keycode, t_general *mother)
{
     mother->gps.event = 0;
     mother->gps.move.x = 0;
     mother->gps.move.y = 0;
     (void)keycode;
     return (0);
}

int events_list(t_general *mother)
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

int exit_game(t_general *mother)
{
     clear_images(mother);
     exit(1);
     return (0);
}

void game_start(t_general *mother)
{
     mother->gps.move.x = 0;
     mother->gps.move.y = 0;
     mother->move = 0;
     mother->args.R[0] = 2500;
     mother->args.R[1] = 1400;

     if (!(mother->mlx.ptr = mlx_init()))
          ft_putstr_fd("Error initialising mlx", 1);
     if (!(mother->mlx.win = mlx_new_window(mother->mlx.ptr, mother->args.R[0], mother->args.R[1], "J' aime les Moules Brite")))
          ft_putstr_fd("Error creating window", 1);
     load_textures(mother);
     draw_map(mother);
     // mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->mlx.img_map.image, 0, 0);
     mlx_hook(mother->mlx.win, 33, 1L << 17, exit_game, mother);
     mlx_hook(mother->mlx.win, KEY_PRESS, 1L << 0, &key_press, mother);
     mlx_hook(mother->mlx.win, KEY_RELEASE, 1L << 1, &key_release, mother);
     // mlx_hook(mother->mlx.win, KEY_PRESS, 1L << 17, &cross_exit, mother);
     mlx_loop_hook(mother->mlx.ptr, &events_list, mother);
     mlx_loop(mother->mlx.ptr);
}