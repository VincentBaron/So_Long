/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vincentbaron1996@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:15:24 by vbaron            #+#    #+#             */
/*   Updated: 2020/04/29 23:59:07 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	f;
	size_t	length;

	length = ft_strlen(dst);
	f = ft_strlen(dst);
	if (length < size)
	{
		i = 0;
		while (src[i] && i + 1 < size - length)
		{
			dst[f] = src[i];
			i++;
			f++;
		}
		dst[f] = '\0';
		return (ft_strlen(src) + length);
	}
	return (ft_strlen(src) + size);
}
