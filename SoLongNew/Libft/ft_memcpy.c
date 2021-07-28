/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:13:59 by vbaron            #+#    #+#             */
/*   Updated: 2020/05/03 17:12:38 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*head;

	if (!dest && !src)
		return ((void *)0);
	head = dest;
	while (n > 0)
	{
		*((char *)head) = *((char *)src);
		head++;
		src++;
		n--;
	}
	return (dest);
}
