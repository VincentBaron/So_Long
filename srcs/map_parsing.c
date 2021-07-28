/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:02:56 by vbaron            #+#    #+#             */
/*   Updated: 2020/10/16 17:29:16 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    splitter_alloc(t_input *args)
{
    char **splitter;
    int x;

    x = 0;
    splitter = ft_split(&(args->line[args->tracker]), ", ");
    if (args->index_i == 1)
    {
        args->R[0] = ft_atoi(splitter[0]);
        args->R[1] = ft_atoi(splitter[1]);
    }
    else
    {
        while (*splitter && x < 3)
        {
            if (args->index_i == 2)
                args->NO.RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 3)
                args->SO.RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 4)
                args->WE.RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 5)
                args->EA.RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 6)
                args->S.RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 7)
                args->F.RGB[x] = ft_atoi(*splitter);
            if (args->index_i == 8)
                args->C.RGB[x] = ft_atoi(*splitter);
            x++;
            splitter++;
        }
    }
}

void     args_definer(t_input *args)
{       
        while (args->line[args->tracker] && !(args->line[args->tracker] >= '0' && args->line[args->tracker] <= '9') && args->line[args->tracker] != '.')
            args->tracker++;
        if (args->line[args->tracker] == '.' && args->index_i == 2)
            (args->NO.path = ft_substr_bis(args->line, args->tracker, ft_strlen(args->line) - args->tracker));
        if (args->line[args->tracker] == '.' && args->index_i == 3)
            (args->SO.path = ft_substr_bis(args->line, args->tracker, ft_strlen(args->line) - args->tracker));
        if (args->line[args->tracker] == '.' && args->index_i == 4)
            (args->WE.path = ft_substr_bis(args->line, args->tracker, ft_strlen(args->line) - args->tracker));
        if (args->line[args->tracker] == '.' && args->index_i == 5)
            (args->EA.path = ft_substr_bis(args->line, args->tracker, ft_strlen(args->line) - args->tracker));
        if (args->line[args->tracker] == '.' && args->index_i == 6)
            (args->S.path = ft_substr_bis(args->line, args->tracker, ft_strlen(args->line) - args->tracker));
        if (args->line[args->tracker] == '.' && args->index_i == 7)
            (args->F.path = ft_substr_bis(args->line, args->tracker, ft_strlen(args->line) - args->tracker));
        if (args->line[args->tracker] == '.' && args->index_i == 8)
            (args->C.path = ft_substr_bis(args->line, args->tracker, ft_strlen(args->line) - args->tracker));
        if (args->line[args->tracker] >= '0' && args->line[args->tracker] <= '9')
            splitter_alloc(args);
}

int    map_parsing(t_input *args)
{
    int res;

    args->index = "1RNSWEXFC";
    (args->map) = ft_strdup("");

    while ((res = get_next_line(args->fd, &(args->line))) != 0)
    {
        if (res == -1)
            return (-1);
        args->tracker = 0;
        while (args->line[args->tracker] == ' ')
            args->tracker++;
        if ((args->index_i = check_charset(args->line[args->tracker], args->index)) == 0)
            create_map(args);
        else if ((args->index_i = check_charset(args->line[args->tracker], args->index)) > 0)
        {
            if (args->index_i == 3 && args->line[args->tracker + 1] == ' ')
                args->index_i = 6;
            args_definer(args);
        }
        ft_free(args->line);
    }
    create_map(args);
    args->matrix = ft_split(args->map, "x");
    ft_free(args->map);
    return (1);
}