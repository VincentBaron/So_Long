/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:49:29 by vbaron            #+#    #+#             */
/*   Updated: 2021/07/25 15:10:21 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char *draw_pixel(t_general *mother, int x, int y)
{
     char *dest;
     
     dest = (mother->mlx.img_map.addr +  x * (mother->mlx.img_map.bpp / 8) + y * mother->mlx.img_map.size_line);
     *(unsigned int *)dest = mother->mlx.img_map.color;
     return (dest);
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
     mother->gps.event = 1;
     printf("keycode: %d\n", keycode);
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
     if (mother->gps.event == 1)
          new_map(mother);
     mother->gps.event = 0;
     return (0);
}
    

void    game_start(t_general *mother)
{    
     mother->gps.move.x = 0;
     mother->gps.move.y = 0;
     mother->args.R[0] = 1000;
     mother->args.R[1] = 700;
     
     if (!(mother->mlx.ptr = mlx_init()))
          ft_putstr_fd("Error initialising mlx", 2);
     if (!(mother->mlx.win = mlx_new_window(mother->mlx.ptr, mother->args.R[0], mother->args.R[1], "J' aime les Moules Brite")))
          ft_putstr_fd("Error creating window", 2);
     load_textures(mother);
     draw_map(mother);
     // mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->mlx.img_map.image, 0, 0);
     mlx_hook(mother->mlx.win, KEY_PRESS, 1L<<0, &key_press, mother);
     mlx_hook(mother->mlx.win, KEY_RELEASE, 1L<<1, &key_release, mother);
     mlx_loop_hook(mother->mlx.ptr, &events_list, mother);
     mlx_loop(mother->mlx.ptr);
}