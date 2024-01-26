/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:11:47 by mben-abd          #+#    #+#             */
/*   Updated: 2023/10/21 00:03:20 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list1 **lst, t_list1 *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
