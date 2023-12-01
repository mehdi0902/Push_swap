/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:03:43 by mben-abd          #+#    #+#             */
/*   Updated: 2023/11/28 18:26:39 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

int	main(int ac, char **av)
{
	(void)ac;
	int i;
	int tmp;
	t_stack_n **a = NULL;
	t_stack_n **b = NULL;
	a = malloc(sizeof(t_stack_n) * ac - 1);
	b = malloc(sizeof(t_stack_n) * ac - 1);
	i = 1;
	while (av[i])
	{
		tmp = ft_atoi(av[i]);
		append(a, tmp);
		i++;
	}
	/*ft_putstr_fd("---------\n", 1);
	stake(a);*/
	find_min(*a);
	stake(a);
	ft_putstr_fd("---------\n", 1);

	stake(a);
	ft_putstr_fd("---------\n", 1);
	stake(b);

	/*
	tant que arv[i]
	{
		int tmp = atoi(arvv[i])
		add_nbr(tmp, list);
		i++;
	}
	*/
}