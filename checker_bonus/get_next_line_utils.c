/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:57:23 by mben-abd          #+#    #+#             */
/*   Updated: 2024/02/07 18:43:56 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// la fonction found_newline va chercher 
// une nouvelle ligne dans la chainé en parametre

int	found_newline(t_liste *stash)
{
	int		i;
	t_liste	*actu;

	if (stash == NULL)
		return (0);
	actu = ft_lst_get_last(stash);
	i = 0;
	while (actu->content[i])
	{
		if (actu->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// cette fonction renvoie un pointeur vers 
// le dernier bout selectionné de notre stash

t_liste	*ft_lst_get_last(t_liste *stash)
{
	t_liste	*actu;

	actu = stash;
	while (actu && actu->next)
		actu = actu->next;
	return (actu);
}

// la fonction va calculer le nombre de char dans la ligne actuelle

void	generate_line(char **line, t_liste *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

// fonction pour free la stash

void	free_stash(t_liste *stash)
{
	t_liste	*actu;
	t_liste	*next;

	actu = stash;
	while (actu)
	{
		free(actu->content);
		next = actu->next;
		free(actu);
		actu = next;
	}
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
