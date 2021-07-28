/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:14:59 by vbaron            #+#    #+#             */
/*   Updated: 2020/06/22 17:54:51 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			check_size(char *str, char *charset)
{
	int size;

	size = 0;
	while (*str)
	{
		while (*str && check_charset(*str, charset) != -1)
			str++;
		if (*str && check_charset(*str, charset) == -1)
		{
			size++;
			while (*str && check_charset(*str, charset) == -1)
				str++;
		}
	}
	return (size);
}

char		*create_string(char *str, char *charset)
{
	int		z;
	char	*split;
	int		x;

	x = 0;
	z = 0;
	while (str[x] && check_charset(str[x], charset) == -1)
		x++;
	if (!(split = (char *)malloc(sizeof(char) * (x + 1))))
		return (NULL);
	x = 0;
	while (str[x] && check_charset(str[x], charset) != -1)
		x++;
	while (str[x] && check_charset(str[x], charset) == -1)
	{
		split[z] = str[x];
		z++;
		x++;
	}
	split[z] = '\0';
	return (split);
}

char		**ft_split(char *str, char *charset)
{
	int		i;
	char	**split_tab;

	if (!(split_tab = (char **)
				malloc(sizeof(char *) * (check_size(str, charset) + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && check_charset(*str, charset) != -1)
			str++;
		if (*str && check_charset(*str, charset) == -1)
		{
			split_tab[i] = create_string(str, charset);
			i++;
			while (*str && check_charset(*str, charset) == -1)
				str++;
		}
	}
	split_tab[i] = NULL;
	return (split_tab);
}
