/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ops1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:57:57 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/20 08:43:03 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	rra_rrb(t_stack_n **a, int i)
{
	t_stack_n	*last;
	t_stack_n	*secondlast;

	{
		last = *a;
		secondlast = NULL;
		if (*a == NULL || (*a)->next == NULL)
			return ;
		while (last->next != NULL)
		{
			secondlast = last;
			last = last->next;
		}
		last->next = *a;
		*a = last;
		secondlast->next = NULL;
		if (i == 0)
			ft_putstr_fd("rra\n", 1);
		else if (i == 1)
			ft_putstr_fd("rrb\n", 1);
	}
}

/*void	rrr(t_stack_n **a, t_stack_n **b)
{
	rra_rrb(a, 3);
	rra_rrb(b, 3);
	ft_putstr_fd("rrr\n", 1);
}*/

void	stake(t_stack_n **a)
{
	t_stack_n	*tmp;

	tmp = *a;
	while (tmp)
	{
		ft_putnbr_fd(tmp->nbr, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
}

static void	rotate(t_stack_n **stack) //Define a function that rotates the stack's top node to the bottom of the stack
{
	t_stack_n	*last_node; //To store a pointer to the last node of a stack

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
	(*stack)->prev = NULL; //Complete setting the current top node by detaching it from its previous top node
	last_node->next->prev = last_node; //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
	last_node->next->next = NULL; //Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
}		

void	ra(t_stack_n **a, bool print) //Rotate the top `a` node to the bottom of the stack, and print the instruction
{
	rotate(a);
	if (!print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_n **b, bool print) //Rotate the top `b` node to the bottom of the stack, and print the instruction
{
	rotate(b);
	if (!print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_n **a, t_stack_n **b, bool print) //Stimultaneously rotate both the top `a` and `b` nodes to the bottom of the stack, and print the instruction
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_putstr_fd("rr\n", 1);
}

static void	rev_rotate(t_stack_n **stack) //Define a funtion that rotates a stack's bottom node, to the top
{
	t_stack_n	*last; //To store the pointer to the last node

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last = find_last(*stack);
	last->prev->next = NULL; //Assign to the `next` attribute of the node before itself, `NULL` effectively setting it as the current last node
	last->next = *stack; //Assign to its own `next` attribute as the top node of the stack
	last->prev = NULL; //Detach itself from the node before it
	*stack = last;  //Complete appending itself to the top of the stack, and now holds the pointer to the top node
	last->next->prev = last; //Update the current last node of the stack
}

void	rra(t_stack_n **a, bool print) //Rotate the bottom of `a` to the top of the stack and print the instruction
{
	rev_rotate(a);
	if (!print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_n **b, bool print) //Rotate the bottom of `b` to the top of the stack and print the instruction
{
	rev_rotate(b);
	if (!print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_n **a, t_stack_n **b, bool print) //Stimultaneously rotate both stacks' bottom nodes to the top of their stacks, halving the cost of instructions
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_putstr_fd("rrr\n", 1);
}