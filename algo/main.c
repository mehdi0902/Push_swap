/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:03:43 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/26 23:59:25 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

int	main(int ac, char **av)
{
	t_stack_n	**a;
	t_stack_n	**b;

	a = NULL;
	b = NULL;
	a = malloc(sizeof(t_stack_n) * ac - 1);
	b = malloc(sizeof(t_stack_n) * ac - 1);
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack_a(a, av + 1);
	if (!stack_sorted(*a))
	{
		if (ft_stack_size(*a) == 2)
			sa_sb(a, 0);
		else if (ft_stack_size(*a) == 3)
			if_three(a);
		else
			turk(a, b);
		return (0);
	}
}
