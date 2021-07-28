/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vincentbaron1996@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:14:40 by vbaron            #+#    #+#             */
/*   Updated: 2020/04/30 17:35:14 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			num;
	unsigned int	nx;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nx = -1 * n;
	}
	else
		nx = n;
	if (nx >= 10)
		ft_putnbr_fd(nx / 10, fd);
	num = nx % 10 + 48;
	ft_putchar_fd(num, fd);
}
