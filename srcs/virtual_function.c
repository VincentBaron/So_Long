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

void ft_clean_cross(t_general *mother)
{
     // (void)mother;
     int i;

     i = 0;
     while (mother->args.matrix[i])
     {
          if (mother->args.matrix[i])
               free(mother->args.matrix[i]);
          i++;
     }
     // if (mother->args.matrix)
     //      free(mother->args.matrix);
     // clear_images(mother);
     // if (mother->mlx.win)
     //      mlx_destroy_window(mother->mlx.ptr, mother->mlx.win);
     // if (mother->mlx.ptr)
          // mlx_destroy_display(mother->mlx.ptr);
     // free(mother->mlx.ptr);
     exit(0);
}

void ft_clean(t_general *mother)
{
     int i;

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
     free(mother->mlx.ptr);
     exit(0);
}

void clear_images(t_general *mother)
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
          ft_clean(mother);
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

int ft_cross(int keycode, t_general *mother)
{
     (void)keycode;
     ft_clean_cross(mother);
     return (0);
}

void game_start(t_general *mother)
{
     mother->gps.move.x = 0;
     mother->gps.event = 0;
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
     mlx_hook(mother->mlx.win, KEY_PRESS, 1L << 0, &key_press, mother);
     mlx_hook(mother->mlx.win, 33, (1L << 17), ft_cross, mother);
     mlx_hook(mother->mlx.win, KEY_RELEASE, 1L << 1, &key_release, mother);
     mlx_loop_hook(mother->mlx.ptr, &events_list, mother);
     mlx_loop(mother->mlx.ptr);
}