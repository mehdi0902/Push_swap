/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:03:43 by mben-abd          #+#    #+#             */
/*   Updated: 2024/02/23 19:43:26 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

char	**rebuild_argv(char **argv, int *argc)
{
	char	**new_argv;
	char	**split_args;
	int		i;
	int		j;

	split_args = ft_split(argv[1], ' ');
	i = 0;
	j = 0;
	while (split_args[i] != NULL)
		i++;
	new_argv = (char **)malloc(sizeof(char *) * (i + 2));
	new_argv[0] = argv[0];
	while (j < i)
	{
		new_argv[j + 1] = split_args[j];
		j++;
	}
	new_argv[i + 1] = NULL;
	*argc = i + 1;
	return (new_argv);
}

char	**process_single_arg(int *argc, char **argv)
{
	if (*argc == 2)
		argv = rebuild_argv(argv, argc);
	return (argv);
}

int	main(int ac, char **av)
{
	t_stack_n	*a;
	t_stack_n	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = process_single_arg(&ac, av);
	}
	init_stack_a(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (ft_stack_size(a) == 2)
			sa_sb(&a, 0);
		else if (ft_stack_size(a) == 3)
			if_three(&a);
		else
			turk(&a, &b);
	}
	free_sa_la(&a);
	return (0);
}
