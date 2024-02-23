/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:41:26 by mben-abd          #+#    #+#             */
/*   Updated: 2024/02/23 19:51:11 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	free_sa_la(t_stack_n **stack)
{
	t_stack_n	*i;
	t_stack_n	*pointeur_s;

	if (!stack)
		return ;
	pointeur_s = *stack;
	while (pointeur_s)
	{
		i = pointeur_s->next;
		pointeur_s->nbr = 0;
		free(pointeur_s);
		pointeur_s = i;
	}
}

t_stack_n	*init_stack_from_args(int argc, char **argv)
{
	t_stack_n	*head;
	t_stack_n	*last_node;
	t_stack_n	*new_node;
	int			i;

	head = NULL;
	last_node = NULL;
	i = 1;
	while (i < argc)
	{
		new_node = create_new_node(argv[i]);
		if (last_node)
		{
			last_node->next = new_node;
			new_node->prev = last_node;
		}
		else
		{
			head = new_node;
		}
		last_node = new_node;
		i++;
	}
	return (head);
}

int	ft_stack_size(t_stack_n *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	is_sorted_and_empty(t_stack_n **stack_a, t_stack_n **stack_b)
{
	if (*stack_b != NULL)
		return (0);
	while (*stack_a && (*stack_a)->next)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			return (0);
		*stack_a = (*stack_a)->next;
	}
	return (1);
}

t_stack_n	*create_new_node(char *value)
{
	t_stack_n	*new_node;

	new_node = malloc(sizeof(t_stack_n));
	if (!new_node)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	new_node->nbr = ft_atoi(value);
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
