/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vincentbaron1996@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:16:03 by vbaron            #+#    #+#             */
/*   Updated: 2020/04/30 12:07:48 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	f;

	i = 0;
	if (little[i] == '\0' || !little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		f = 0;
		while (big[i + f] == little[f] && i + f < len)
		{
			if (little[f + 1] == '\0')
				return ((char *)&big[i]);
			f++;
		}
		i++;
	}
	return (NULL);
}
