/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:43:17 by mben-abd          #+#    #+#             */
/*   Updated: 2023/10/13 14:43:17 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	t;
	void	*ptr;

	t = nmemb * size;
	ptr = malloc(t);
	if (ptr != NULL)
		ft_memset(ptr, 0, t);
	return (ptr);
}
