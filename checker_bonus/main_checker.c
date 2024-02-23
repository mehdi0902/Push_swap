/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:06:10 by mben-abd          #+#    #+#             */
/*   Updated: 2024/02/23 19:49:49 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	print_double_char_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

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

int	main(int argc, char **argv)
{
	t_stack_n	*stack_a;
	t_stack_n	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	argv = process_single_arg(&argc, argv);
	stack_a = init_stack_from_args(argc, argv);
	error_bonus(&stack_a, argv);
	get_instructions(&stack_a, &stack_b);
	if (is_sorted_and_empty(&stack_a, &stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_sa_la(&stack_a);
	free_sa_la(&stack_b);
	return (0);
}
