/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:13:03 by mben-abd          #+#    #+#             */
/*   Updated: 2024/02/23 19:43:14 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

int	do_commands(char *line, t_stack_n **stack_a, t_stack_n **stack_b)
{
	if (!(ft_strncmp(line, "sa\n", 3)))
		sa_sb(stack_a, 15);
	else if (!(ft_strncmp(line, "sb\n", 3)))
		sa_sb(stack_b, 14);
	else if (!(ft_strncmp(line, "ss\n", 3)))
		ss(stack_a, stack_b, 78);
	else if (!(ft_strncmp(line, "pa\n", 3)))
		pa(stack_a, stack_b, 35);
	else if (!(ft_strncmp(line, "pb\n", 3)))
		pb(stack_a, stack_b, 73);
	else if (!(ft_strncmp(line, "ra\n", 3)))
		ra_rb(stack_a, 773);
	else if (!(ft_strncmp(line, "rb\n", 3)))
		ra_rb(stack_b, 178);
	else if (!(ft_strncmp(line, "rr\n", 3)))
		rr(stack_a, stack_b, 48);
	else
		do_commands2(line, stack_a, stack_b);
	return (0);
}

int	do_commands2(char *line, t_stack_n **stack_a, t_stack_n **stack_b)
{
	if (!(ft_strncmp(line, "rra\n", 4)))
		rra_rrb(stack_a, 34);
	else if (!(ft_strncmp(line, "rrb\n", 4)))
		rra_rrb(stack_b, 39);
	else if (!(ft_strncmp(line, "rrr\n", 4)))
		rrr(stack_a, stack_b, 58);
	else
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	return (1);
}

void	get_instructions(t_stack_n **stack_a, t_stack_n **stack_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		do_commands(instruction, stack_a, stack_b);
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
}
