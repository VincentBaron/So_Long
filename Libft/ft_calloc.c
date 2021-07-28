/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vincentbaron1996@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:11:04 by vbaron            #+#    #+#             */
/*   Updated: 2020/04/27 13:11:06 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nmemb, int size)
{
	void *array;

	if (!(array = (void *)malloc(nmemb * size)))
		return (0);
	ft_bzero(array, (size * nmemb));
	return ((void *)array);
}
