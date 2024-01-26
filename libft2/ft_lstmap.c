/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:28:45 by mben-abd          #+#    #+#             */
/*   Updated: 2023/11/15 21:37:15 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1	*ft_lstmap(t_list1 *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list1	*changed_list;
	t_list1	*changed_elem;

	changed_list = NULL;
	while (lst)
	{
		changed_elem = ft_lstnew(f(lst->content));
		if (!changed_elem)
		{
			ft_lstclear(&changed_list, del);
			return (NULL);
		}
		ft_lstadd_back(&changed_list, changed_elem);
		lst = lst->next;
	}
	return (changed_list);
}
