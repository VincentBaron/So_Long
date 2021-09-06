/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaron <vincentbaron1996@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 13:12:38 by vbaron            #+#    #+#             */
/*   Updated: 2021/07/28 17:35:18 by vbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**temp;

	if ((*lst) != 0 && del)
	{
		while ((*lst) != 0)
		{
			temp = lst;
			(*del)((*lst)->content);
			free(*lst);
			*lst = (*temp)->next;
		}
	}
	else
		return ;
}
