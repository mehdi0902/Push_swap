/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:32:10 by mben-abd          #+#    #+#             */
/*   Updated: 2023/11/15 21:37:28 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list1	*ft_lstnew(void *content)
{
	t_list1	*new;

	new = malloc(sizeof(t_list1));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
