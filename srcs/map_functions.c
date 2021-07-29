/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:31:48 by vbaron            #+#    #+#             */
/*   Updated: 2021/07/29 17:06:05 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void pixel_color(t_general *mother, char *type)
{
     unsigned int R;
     unsigned int G;
     unsigned int B;

     if (ft_strncmp(type, "floor", ft_strlen(type)) == 0)
     {
          R = 255;
          G = 255;
          B = 255;
     }
     if (ft_strncmp(type, "wall", ft_strlen(type)) == 0)
     {
          R = 0;
          G = 0;
          B = 0;
     }
     if (ft_strncmp(type, "out", ft_strlen(type)) == 0)
     {
          R = 172;
          G = 93;
          B = 93;
     }
     if (ft_strncmp(type, "player", ft_strlen(type)) == 0)
     {
          R = 70;
          G = 70;
          B = 70;
     }
     if (ft_strncmp(type, "sprite", ft_strlen(type)) == 0)
     {
          R = 32;
          G = 178;
          B = 170;
     }
     mother->mlx.img_map.color = (R << 16) + (G << 8) + B;
}

void draw_square(t_general *mother, char *type)
{
     int x;
     int y;

     y = 0;
     while (y <= mother->map.size_y)
     {
          x = 0;
          while (x <= mother->map.size_x)
          {

               (x < 1 || x > (mother->map.size_x - 1)) || (y < 1 || y > (mother->map.size_y - 1)) ? pixel_color(mother, "out") : pixel_color(mother, type);
               draw_pixel(mother, y + mother->map.size_y * mother->map.track_y, x + mother->map.size_x * mother->map.track_x);
               x++;
          }
          y++;
     }
}

void draw_map(t_general *mother)
{
     char *move_str;

     move_str = ft_itoa(mother->move);
     mother->move++;
     mother->map.track_x = 0;
     mother->map.size_x = 64;
     while (mother->args.matrix[mother->map.track_x])
     {
          mother->map.track_y = 0;
          mother->map.size_y = 64;
          while (mother->args.matrix[mother->map.track_x][mother->map.track_y])
          {
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == '1')
                    mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->args.wall, mother->map.track_y * 64, mother->map.track_x * 64);
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == '0')
                    mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->args.floor, mother->map.track_y * 64, mother->map.track_x * 64);
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'P')
               {
                    mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->args.floor, mother->map.track_y * 64, mother->map.track_x * 64);
                    mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->args.player, mother->map.track_y * 64, mother->map.track_x * 64);
               }
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'C')
               {
                    mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->args.floor, mother->map.track_y * 64, mother->map.track_x * 64);
                    mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->args.coins1, mother->map.track_y * 64, mother->map.track_x * 64);
               }
               if (mother->args.matrix[mother->map.track_x][mother->map.track_y] == 'E')
               {
                    mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->args.floor, mother->map.track_y * 64, mother->map.track_x * 64);
                    mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->args.exit, mother->map.track_y * 64, mother->map.track_x * 64);
               }

               mother->map.track_y++;
          }
          mother->map.track_x++;
     }
      mlx_string_put(mother->mlx.ptr, mother->mlx.win, 5, 5, mother->mlx.img_map.color, move_str);
}

void redefine_pos(t_general *mother)
{
     t_coor old_pos;
     char *block;

     if (mother->collectibles != 0)
          block = ft_strdup("1E");
     else
          block = ft_strdup("1");

     old_pos.y = mother->gps.pos.y;
     old_pos.x = mother->gps.pos.x;

     if (mother->gps.move.y == -1 && check_charset(mother->args.matrix[(int)(mother->gps.pos.y - 1)][(int)mother->gps.pos.x], block) == -1)
     {
          mother->gps.pos.y -= 1;
          mother->args.matrix[(int)mother->gps.pos.y][(int)mother->gps.pos.x] = 'P';
          mother->args.matrix[(int)old_pos.y][(int)old_pos.x] = '0';
     }

     else if (mother->gps.move.y == 1 && check_charset(mother->args.matrix[(int)(mother->gps.pos.y + 1)][(int)mother->gps.pos.x], block) == -1)
     {
          mother->gps.pos.y += 1;
          mother->args.matrix[(int)mother->gps.pos.y][(int)mother->gps.pos.x] = 'P';
          mother->args.matrix[(int)old_pos.y][(int)old_pos.x] = '0';
     }
     else if (mother->gps.move.x == -1 && check_charset(mother->args.matrix[(int)mother->gps.pos.y][(int)(mother->gps.pos.x - 1)], block) == -1)
     {
          mother->gps.pos.x -= 1;
          mother->args.matrix[(int)mother->gps.pos.y][(int)mother->gps.pos.x] = 'P';
          mother->args.matrix[(int)old_pos.y][(int)old_pos.x] = '0';
     }
     else if (mother->gps.move.x == +1 && check_charset(mother->args.matrix[(int)mother->gps.pos.y][(int)(mother->gps.pos.x + 1)], block) == -1)
     {
          mother->gps.pos.x += 1;
          mother->args.matrix[(int)mother->gps.pos.y][(int)mother->gps.pos.x] = 'P';
          mother->args.matrix[(int)old_pos.y][(int)old_pos.x] = '0';
     }
     free(block);
}

void check_collectibles(t_general *mother)
{
     int i;
     int j;

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

void final(t_general *mother)
{
     mother->map.track_x = 0;
     mother->map.size_x = 64;
     while (mother->args.matrix[mother->map.track_x])
     {
          mother->map.track_y = 0;
          mother->map.size_y = 64;
          while (mother->args.matrix[mother->map.track_x][mother->map.track_y])
          {
               mlx_put_image_to_window(mother->mlx.ptr, mother->mlx.win, mother->args.floor, mother->map.track_y * 64, mother->map.track_x * 64);
               mother->map.track_y++;
          }
          mother->map.track_x++;
     }

     mlx_string_put(mother->mlx.ptr, mother->mlx.win, 200, 200, mother->mlx.img_map.color, "YOU WON!");
}

int new_map(t_general *mother)
{
     redefine_pos(mother);
          draw_map(mother);
     return (0);
}