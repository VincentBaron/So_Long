/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:51:16 by vbaron            #+#    #+#             */
/*   Updated: 2021/09/06 11:29:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	position_info(t_general *mother)
{
	int	i;
	int	f;

	mother->gps.pos.y = -1;
	mother->gps.pos.x = -1;
	i = 0;
	while (mother->args.matrix[i])
	{
		f = 0;
		while (mother->args.matrix[i][f])
		{
			if (mother->args.matrix[i][f] == 'P')
			{
				mother->gps.pos.x = f + 0.5;
				mother->gps.pos.y = i + 0.5;
				break ;
			}
			f++;
		}
		i++;
	}
}
