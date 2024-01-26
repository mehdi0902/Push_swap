/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:10:07 by mben-abd          #+#    #+#             */
/*   Updated: 2023/10/13 16:10:16 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	size_t	taille;
	char	*cop;

	taille = ft_strlen(source);
	cop = (char *)malloc(taille + 1);
	if (source == NULL)
		return (NULL);
	if (cop != NULL)
		(ft_strlcpy(cop, source, taille + 1));
	return (cop);
}
