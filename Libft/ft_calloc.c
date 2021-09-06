/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:11:04 by vbaron            #+#    #+#             */
/*   Updated: 2021/07/28 17:23:38 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nmemb, int size)
{
	void	*array;

	array = (void *)malloc(nmemb * size);
	if (!array)
		return (0);
	ft_bzero(array, (size * nmemb));
	return ((void *)array);
}
