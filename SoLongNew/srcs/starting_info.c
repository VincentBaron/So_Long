/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:51:16 by vbaron            #+#    #+#             */
/*   Updated: 2021/07/25 13:57:13 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    position_info(t_general *mother)
{
    int i;
    int f;
    
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
                break;
            }
            f++;
        }
        i++;
    }
}