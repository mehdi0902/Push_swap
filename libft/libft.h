/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:41:24 by mben-abd          #+#    #+#             */
/*   Updated: 2023/11/15 20:37:13 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int i);
int					ft_isalpha(int i);
int					ft_isascii(int i);
int					ft_isdigit(int i);
int					ft_isprint(int i);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *source);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
int					ft_strlen(const char *str);
int					ft_strncmp(const char *s1, char *s2, size_t n);
char				*ft_strnstr(const char *botte, const char *aiguille,
						size_t n);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int i);
int					ft_toupper(int i);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *str, char c);
char				*ft_itoa(int n);
void				ft_putendl_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list1;

t_list1				*ft_lstnew(void *content);
int					ft_lstsize(t_list1 *lst);
t_list1				*ft_lstlast(t_list1 *lst);
void				ft_lstadd_front(t_list1 **lst, t_list1 *new);
void				ft_lstdelone(t_list1 *lst, void (*del)(void *));
void				ft_lstclear(t_list1 **lst, void (*del)(void *));
void				ft_lstiter(t_list1 *lst, void (*f)(void *));
void				ft_lstadd_back(t_list1 **lst, t_list1 *new);
t_list1				*ft_lstmap(t_list1 *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
