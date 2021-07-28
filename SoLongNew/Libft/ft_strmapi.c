/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:15:43 by vbaron            #+#    #+#             */
/*   Updated: 2020/05/03 20:29:23 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*snew;
	unsigned int	size;

	if (!s || !f)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	if (!(snew = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	size = 0;
	while (s[size])
	{
		snew[size] = (*f)(size, s[size]);
		size++;
	}
	snew[size] = '\0';
	return (snew);
}
