/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:17:10 by mben-abd          #+#    #+#             */
/*   Updated: 2023/10/20 23:40:31 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list1 **lst, void (*del)(void *))
{
	t_list1	*next;

	while (*lst)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
