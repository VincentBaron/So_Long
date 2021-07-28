/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:13:35 by vbaron            #+#    #+#             */
/*   Updated: 2020/05/03 17:26:50 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	if (!dest && !src)
		return ((void *)0);
	while (n > 0)
	{
		*((unsigned char *)dest) = *((unsigned char *)src);
		if (*((unsigned char *)src) == (unsigned char)c)
			return ((unsigned char *)dest + 1);
		dest++;
		src++;
		n--;
	}
	return (NULL);
}
