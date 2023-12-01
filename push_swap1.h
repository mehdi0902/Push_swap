/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:08:33 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/01 21:43:08 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP1_H
# define PUSH_SWAP1_H

# include "libft2/ft_printf/ft_printf.h"
# include "libft2/libft.h"
# include <limits.h>
# include <stdbool.h>
//
// lsa structure qui prend 
//
typedef struct s_stack_n
{
	int					nbr;
	int					index;
	int					cmd_cost;
	bool				middle_up;
	bool				cheap;
	struct s_stack_n	*target_n;
	struct s_stack_n	*next;
	struct s_stack_n	*prev;
}						t_stack_n;
//
// ALGO -->
//
t_stack_n				*find_last(t_stack_n *stack);
void					append(t_stack_n **top, int newnbr);
int						ft_stack_size(t_stack_n *stack);
bool					stack_sorted(t_stack_n *stack);
t_stack_n				*find_min(t_stack_n *stack);
t_stack_n				*find_max(t_stack_n *stack);
t_stack_n				*cheapest_nbr(t_stack_n *stack);
void					mid_index(t_stack_n *stack);
void					plan_to_push(t_stack_n **stack, t_stack_n *top_n,
							char a_b);
void					aim_for_a(t_stack_n *a, t_stack_n *b);
void					cost_a(t_stack_n *a, t_stack_n *b);
//
// les operations -->
//
void					rr(t_stack_n **a, t_stack_n **b);
void					ra_rb(t_stack_n **a, int i);
void					pa_pb(t_stack_n **a, t_stack_n **b, int i);
void					ss(t_stack_n **a, t_stack_n **b);
void					sa_sb(t_stack_n **a, int i);
void					rra_rrb(t_stack_n **a, int i);
void					rrr(t_stack_n **a, t_stack_n **b);
void					stake(t_stack_n **a);
void					ft_putstr_fd(char *s, int fd);
void					if_three(t_stack_n **a);

#endif