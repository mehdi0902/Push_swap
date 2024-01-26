/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:28:34 by mben-abd          #+#    #+#             */
/*   Updated: 2023/10/18 23:10:13 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_liberez_tous_mes_copains(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs);
		i++;
	}
	free(strs);
}

int	count_word(char *str, char c)
{
	int	i;
	int	sah;

	i = 0;
	sah = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			sah++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (sah);
		}
		i++;
	}
	return (sah);
}

void	ft_strcpy(char *w, char *str, char c, int j)
{
	int	i;

	i = 0;
	while (str[j] != '\0' && str[j] == c)
		j++;
	while (str[j + i] != c && str[j + i] != '\0')
	{
		w[i] = str[j + i];
		i++;
	}
	w[i] = '\0';
}

char	*ft_malloc_str(char *str, char c, int *o)
{
	char	*w;
	int		j;
	int		len;
	int		i;

	j = *o;
	w = NULL;
	while (str[*o] != '\0' && str[*o] == c)
		*o += 1;
	len = 0;
	while (str[*o + len] != '\0' && str[*o + len] != c)
		len++;
	w = (char *)malloc(sizeof(char) * (len + 1));
	if (w == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		w[i] = str[*o + i];
		i++;
	}
	w[i] = '\0';
	*o += len;
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		p;

	if (s == NULL)
		return (NULL);
	i = 0;
	p = 0;
	j = count_word((char *)s, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = ft_malloc_str(((char *)s), c, &p);
		if (strs[i] == NULL)
		{
			ft_liberez_tous_mes_copains(strs);
		}
		i++;
	}
	return (strs);
}
