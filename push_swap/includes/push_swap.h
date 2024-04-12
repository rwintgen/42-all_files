/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:26:13 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/25 13:11:43 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				nb;
	int				pos;
	int				cost;
	int				top_half;
	int				cheapest;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// Errors

void	ft_free_stack(t_node **stack);
void	ft_err_free(int err_id, t_node **stack);
int		ft_err_dup(t_node *stack, int nb);
int		ft_err_syntax(char *nb);
int		ft_err_intmax(char *nb);

// Utils

void	ft_free_split(char **av);
void	ft_lst_append(t_node **stack, int nb);
void	ft_init_stack_a(t_node **stack_a, char **argv);
int		ft_stack_len(t_node *stack);
int		ft_stack_sorted(t_node *stack);

// Utils 2

t_node	*ft_get_max_node(t_node *stack);
t_node	*ft_get_min_node(t_node *stack);
t_node	*ft_get_last_node(t_node *stack);
t_node	*ft_get_cheapest(t_node *stack);

// Algo utils

void	ft_init_data_a(t_node *stack_a, t_node *stack_b);
void	ft_init_data_b(t_node *stack_a, t_node *stack_b);
void	ft_bring_to_top(t_node **a, t_node **b, t_node *top_a, t_node *top_b);
void	ft_transfer_to_b(t_node **stack_a, t_node **stack_b);
void	ft_transfer_to_a(t_node **stack_a, t_node **stack_b);

// Data

void	ft_tokenize(t_node *stack);
void	ft_targetize_a(t_node *stack_a, t_node *stack_b);
void	ft_targetize_b(t_node *stack_a, t_node *stack_b);
void	ft_cost_analyze(t_node *stack_a, t_node *stack_b);
void	ft_find_cheapest(t_node *stack);

// Algo

void	ft_easy_sort(t_node **stack_a, int stack_len);
void	ft_hard_sort(t_node **stack_a, t_node **stack_b);

// Commands

void	ft_swap(t_node **top);
void	ft_push(t_node **src, t_node **dst);
void	ft_rotate(t_node **top);
void	ft_rev_rotate(t_node **top);
void	sa(t_node **stack_a, int print);
void	sb(t_node **stack_b, int print);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);
void	ra(t_node **stack_a, int print);
void	rb(t_node **stack_b, int print);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a, int print);
void	rrb(t_node **stack_b, int print);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif