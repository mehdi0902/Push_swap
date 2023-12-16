/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:03:43 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/16 05:03:21 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

int	main(int ac, char **av)
{
	//int i;
	//int tmp = 0;
	t_stack_n **a = NULL;
	t_stack_n **b = NULL;
	a = malloc(sizeof(t_stack_n) * ac - 1);
	b = malloc(sizeof(t_stack_n) * ac - 1);
	//i = 1;
	if (ac == 1 || (ac == 2 && !av[1][0])) 
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' '); 
	init_stack_a(a, av + 1);	

	//ft_putstr_fd("salllll\n", 1);
	
	
	if (!stack_sorted(*a)) 
	{
		//ft_putstr_fd("salllll\n", 1);

		if (ft_stack_size(*a) == 2) 
			sa_sb(a, 0);
		else if (ft_stack_size(*a) == 3) 
			if_three(a);
		else
			turk(a, b);

		//ft_putstr_fd("salllll\n", 1);
	return (0);
}
	/*while (av[i])
	{
		tmp = ft_atoi(av[i]);
		append(a, tmp);
		i++;
	}
	ft_putstr_fd("---------\n", 1);
	stake(a);
	find_min(*a);
	stake(a);
	ft_putstr_fd("---------\n", 1);

	stake(a);
	ft_putstr_fd("---------\n", 1);
	stake(b);
	tant que arv[i]
	{
		int tmp = atoi(arvv[i])
		add_nbr(tmp, list);
		i++;
	}
	*/

}