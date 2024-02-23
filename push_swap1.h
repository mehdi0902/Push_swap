/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:08:33 by mben-abd          #+#    #+#             */
/*   Updated: 2024/02/23 19:40:14 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP1_H
# define PUSH_SWAP1_H

# include "checker_bonus/get_next_line.h"
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
void					append(t_stack_n **stack, int n);
int						ft_stack_size(t_stack_n *stack);
bool					stack_sorted(t_stack_n *stack);
t_stack_n				*find_min(t_stack_n *stack);
t_stack_n				*find_max(t_stack_n *stack);
t_stack_n				*cheapest_nbr(t_stack_n *stack);
void					mid_index(t_stack_n *stack);
void					plan_to_push(t_stack_n **stack, t_stack_n *top_n,
							char a_b);
void					aim_for_b(t_stack_n *a, t_stack_n *b);
void					cost_a(t_stack_n *a, t_stack_n *b);
void					aim_for_a(t_stack_n *a, t_stack_n *b);
void					turk(t_stack_n **a, t_stack_n **b);
void					rev_rotate_a_and_b(t_stack_n **a, t_stack_n **b,
							t_stack_n *cheap);
void					rotate_a_and_b(t_stack_n **a, t_stack_n **b,
							t_stack_n *cheap);
void					set_cheap(t_stack_n *stack);
void					init_a_to_b(t_stack_n *a, t_stack_n *b);
void					init_b_to_a(t_stack_n *a, t_stack_n *b);
void					mv_b_to_a(t_stack_n **a, t_stack_n **b);
void					mv_a_to_b(t_stack_n **a, t_stack_n **b);
void					min_on_top(t_stack_n **a);
void					init_stack_a(t_stack_n **a, char **av);
int						if_duplicate(t_stack_n *a, int n);
void					liberez_tout_mes_copains(t_stack_n **a);
void					free_sa_la(t_stack_n **stack);
int						synthol(char *str_n);
//
// les operations -->
//
void					rr(t_stack_n **a, t_stack_n **b, int i);
void					ra_rb(t_stack_n **a, int i);
// void					pa_pb(t_stack_n **a, t_stack_n **b, int i);
void					pb(t_stack_n **a, t_stack_n **b, int i);
void					pa(t_stack_n **a, t_stack_n **b, int i);
void					ss(t_stack_n **a, t_stack_n **b, int i);
void					sa_sb(t_stack_n **a, int i);
void					rra_rrb(t_stack_n **a, int i);
void					rrr(t_stack_n **a, t_stack_n **b, int i);
void					stake(t_stack_n **a);
void					ft_putstr_fd(char *s, int fd);
void					if_three(t_stack_n **a);
// void	rr(t_stack_n **a, t_stack_n **b, bool print);
// void	rb(t_stack_n **b, bool print);
// void	ra(t_stack_n **a, bool print);
// void	rrr(t_stack_n **a, t_stack_n **b, bool print);
// void	rrb(t_stack_n **b, bool print);
// void	rra(t_stack_n **a, bool print);
//
//
// BONUS ----->
void					stake2(t_stack_n *stack);
int						do_commands(char *line, t_stack_n **stack_a,
							t_stack_n **stack_b);
int						do_commands2(char *line, t_stack_n **stack_a,
							t_stack_n **stack_b);
void					get_instructions(t_stack_n **stack_a,
							t_stack_n **stack_b);
int						is_sorted_and_empty(t_stack_n **stack_a,
							t_stack_n **stack_b);

t_stack_n				*init_stack_from_args(int argc, char **argv);
void					error_bonus(t_stack_n **a, char **av);
int						has_duplicates(t_stack_n *head);
char					**process_single_arg(int *argc, char **argv);
t_stack_n				*create_new_node(char *value);
#endif