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
    (void)mother;
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
    
    //free_program(mother);
    exit(1);
}

int main(int argc, char **argv)
{
    t_general mother;

    if (argc != 2)
      error(&mother, 2);
    if ((mother.args.fd = open(argv[1], O_RDONLY)) == -1)
    {
        error(&mother, 2);
        return (0);
    }
    map_parsing(&(mother.args), &mother);
    int i;
    i = 0;
    position_info(&mother);
    mother.collectibles = 1;
    mother.exit = 1;
    game_start(&mother);
    system("leaks a.out");
    return (0);
}