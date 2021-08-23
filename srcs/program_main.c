/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:38:34 by vbaron            #+#    #+#             */
/*   Updated: 2021/07/29 17:06:56 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    error(t_general *mother, int e)
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
    if (mother->args.map)
        free(mother->args.map);
    if (e == 1)
        ft_putstr_fd("Error\n1: Map is unvalid", 1);
    if (e == 2)
        ft_putstr_fd("Error\n2: Arguments invalid", 1);
    if (e == 3)
        ft_putstr_fd("Error\n3: Malloc Error", 1);
    if (e == 4)
        ft_putstr_fd("Error\n4: Too many players", 1);
    if (e == 5)
        ft_putstr_fd("Error\n5: Could not create bmp image", 1);
    
    exit(1);
}

void init_image(t_img *img)
{
    img->image = NULL;
    img->addr = NULL;
    img->bpp = 0;
    img->color = 0;
    img->endian = 0;
    img->size_line = 0;
    img->width = 0;
    img->height = 0;
}

void init_mother(t_general *mother)
{
    init_image(&(mother->args.player));
    init_image(&(mother->args.coins1));
    init_image(&(mother->args.exit));
    init_image(&(mother->args.wall));
    init_image(&(mother->args.floor));
    mother->mlx.ptr = NULL;
    mother->mlx.win = NULL;
    mother->args.matrix = NULL;
}

int main(int argc, char **argv)
{
    t_general mother;


    init_mother(&mother);
    if (argc != 2)
      error(&mother, 2);
    if ((mother.args.fd = open(argv[1], O_RDONLY)) == -1)
    {
        error(&mother, 2);
        return (0);
    }
    map_parsing(&(mother.args), &mother);
    position_info(&mother);
    mother.collectibles = 1;
    mother.exit = 1;
    game_start(&mother);
    clear_images(&mother);
    return (0);
}