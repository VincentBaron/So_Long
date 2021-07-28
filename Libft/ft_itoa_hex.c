/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:12:06 by vbaron            #+#    #+#             */
/*   Updated: 2020/05/26 16:41:24 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*alloc_itoa_hex(unsigned int n, int size, int sign)
{
	char	*itoa;

	if (!(itoa = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	itoa[size] = '\0';
	size--;
	if (n == 0)
		itoa[size] = '0';
	while (n > 0)
	{
		if (n % 16 <= 9)
			itoa[size] = n % 16 + '0';
		else
			itoa[size] = n % 16 - 10 + 'a';
		n = n / 16;
		size--;
	}
	if (sign == 1)
		itoa[size] = '-';
	return (itoa);
}

int		get_size_hex(int n)
{
	int	size;

	size = 0;
	if (n == 0)
	{
		size = 1;
		return (size);
	}
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char	*ft_itoa_hex(int n)
{
	unsigned int	nbx;
	int				size;
	int				sign;
	char			*itoa;

	size = get_size_hex(n);
	sign = 0;
	if (n < 0)
	{
		nbx = (unsigned int)(-1 * n);
		sign++;
	}
	else
		nbx = (unsigned int)n;
	itoa = alloc_itoa_hex(nbx, size, sign);
	return (itoa);
}
