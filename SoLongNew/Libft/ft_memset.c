/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vincentbaron1996@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:14:12 by vbaron            #+#    #+#             */
/*   Updated: 2020/04/27 13:14:13 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*x;

	i = 0;
	x = s;
	while (i < n)
	{
		*x = c;
		x++;
		i++;
	}
	return (s);
}
