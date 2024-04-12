/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:33:34 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/30 15:21:34 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rev_rotate(t_node **top)
{
	t_node	*last;
	t_node	*b_last;

	if (!(*top) || !(*top)->next)
		return ;
	last = ft_get_last_node(*top);
	b_last = last->prev;
	(*top)->prev = last;
	last->prev = NULL;
	last->next = *top;
	b_last->next = NULL;
	*top = last;
}

void	rra(t_node **stack_a, int print)
{
	ft_rev_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_node **stack_b, int print)
{
	ft_rev_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_printf("rrr\n");
}
