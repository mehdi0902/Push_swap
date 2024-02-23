/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:49:27 by mben-abd          #+#    #+#             */
/*   Updated: 2024/02/23 19:53:09 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

/*
void	free_stack(t_stack_n *stack)
{
	if (stack)
		free(stack);
}

void	exit_sans_error(t_stack_n *stack_a, t_stack_n *stack_b,
		char **arguments,
		int argc)
{
	if (argc == 2)
		free_arguments(arguments);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(0);
}

void	free_arguments(char **arguments)
{
	int	i;

	if (!arguments)
		return ;
	i = 0;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}
*/

/*bool check_duplicates(const t_stack_n *head)
{
	const t_stack_n	*current = head;
	const t_stack_n	*to_compare;
	t_stack_n		*current;
	t_stack_n		*comparer;
	t_stack_n		*current;
	t_stack_n		*comparer;

	while (current != NULL)
	{
		to_compare = current->next;
		while (to_compare != NULL)
		{
			if (current->nbr == to_compare->nbr)
				return (true);
			to_compare = to_compare->next;
		}
		current = current->next;
	}
	return (false);
}*/
int	has_duplicates(t_stack_n *head)
{
	t_stack_n	*current;
	t_stack_n	*comparer;

	current = head;
	comparer = NULL;
	while (current != NULL)
	{
		comparer = current->next;
		while (comparer != NULL)
		{
			if (current->nbr == comparer->nbr)
			{
				return (1);
			}
			comparer = comparer->next;
		}
		current = current->next;
	}
	return (0);
}

int	synthol(char *str_n)
{
	int	i;

	i = 0;
	while (str_n[i])
	{
		if (!(str_n[i] >= '0' && str_n[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

/*void	free_sa_la(t_stack_n **stack)
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
}*/
void	liberez_tout_mes_copains(t_stack_n **a)
{
	free_sa_la(a);
	ft_putstr_fd("Error", 1);
	exit(1);
}

void	error_bonus(t_stack_n **a, char **av)
{
	int		i;
	long	n;

	i = 1;
	if (has_duplicates(*a))
		liberez_tout_mes_copains(a);
	while (av[i])
	{
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			liberez_tout_mes_copains(a);
		if (synthol(av[i]))
			liberez_tout_mes_copains(a);
		i++;
	}
}
