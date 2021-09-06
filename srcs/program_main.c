/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:38:34 by vbaron            #+#    #+#             */
/*   Updated: 2021/09/06 14:25:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_image(t_img *img)
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

void	init_mother(t_general *mother)
{
	init_image(&(mother->args.player));
	init_image(&(mother->args.coins1));
	init_image(&(mother->args.exit));
	init_image(&(mother->args.wall));
	init_image(&(mother->args.floor));
	mother->mlx.ptr = NULL;
	mother->mlx.win = NULL;
	mother->args.matrix = NULL;
	mother->args.map = NULL;
	mother->moves = 0;
}

int	check_file(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (i < 4)
		return (0);
	i -= 3;
	if (ft_strncmp(&file[i], ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_general	mother;

	init_mother(&mother);
	if (argc != 2)
		error(&mother, 2);
	if (!check_file(argv[1]))
		error(&mother, 2);
	mother.args.fd = open(argv[1], __O_DIRECTORY);
	if (mother.args.fd != -1)
		error(&mother, 2);
	mother.args.fd = open(argv[1], O_RDONLY);
	if (mother.args.fd == -1)
		error(&mother, 2);
	map_parsing(&(mother.args), &mother);
	position_info(&mother);
	mother.collectibles = 1;
	mother.exit = 1;
	game_start(&mother);
	clear_images(&mother);
	return (0);
}
