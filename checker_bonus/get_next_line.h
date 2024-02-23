/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:49:27 by mben-abd          #+#    #+#             */
/*   Updated: 2024/02/07 18:45:29 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> // REMOVE FOR PUSH
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_liste
{
	char			*content;
	struct s_liste	*next;
}					t_liste;

char				*get_next_line(int fd);
int					found_newline(t_liste *stash);
t_liste				*ft_lst_get_last(t_liste *stash);
void				read_and_stash(int fd, t_liste **stash);
void				add_to_stash(t_liste **stash, char *buf, int readed);
void				extract_line(t_liste *stash, char **line);
void				generate_line(char **line, t_liste *stash);
void				clean_stash(t_liste **stash);
int					ft_strlen(const char *str);
void				free_stash(t_liste *stash);
#endif
