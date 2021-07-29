/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:02:56 by vbaron            #+#    #+#             */
/*   Updated: 2021/07/29 14:44:43 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void splitter_alloc(t_input *args)
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

void args_definer(t_input *args)
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

int check_spaces(t_general *mother, int i, int f)
{
    if (i - 1 < 0 || f - 1 < 0 || (f + 1 == (int)ft_strlen(mother->args.matrix[i])))
        return (-1);

    if (check_charset(mother->args.matrix[i - 1][f], "01PEC") == -1 || check_charset(mother->args.matrix[i + 1][f], "01PEC") == -1 || check_charset(mother->args.matrix[i][f - 1], "01PEC") == -1 || check_charset(mother->args.matrix[i][f + 1], "01PEC") == -1)
        return (-1);
    return (0);
}

void check_map(t_general *mother)
{
    int i;
    int f;
    int player_count;
    int sprite_count;
    int exit_count;
    int map_length;

    player_count = 0;
    sprite_count = 0;
    exit_count = 0;
    i = 0;
    while (mother->args.matrix[i])
    {
        f = 0;
        while (mother->args.matrix[i][f])
        {
            if (mother->args.matrix[i][f] == 'P')
                player_count++;
            if (mother->args.matrix[i][f] == 'C')
                sprite_count++;
            if (mother->args.matrix[i][f] == 'E')
                exit_count++;
            if (mother->args.matrix[i][f] == '0')
                if (check_spaces(mother, i, f))
                    error(mother, 1);
            f++;
        }
        if (i == 0)
            map_length = f;
        else if (f != map_length)
            error(mother, 1);
        i++;
    }
    if (exit_count == 0 || player_count == 0 || sprite_count == 0)
        error(mother, 1);
}

int map_parsing(t_input *args, t_general *mother)
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
    ft_free(args->line);
    create_map(args);
    args->matrix = ft_split(args->map, "x");
    check_map(mother);
    ft_free(args->map);
    return (1);
}