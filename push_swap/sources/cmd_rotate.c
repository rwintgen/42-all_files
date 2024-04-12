/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:33:34 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/30 15:21:08 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_node **top)
{
	t_node	*sec;
	t_node	*last;

	if (!(*top) || !(*top)->next)
		return ;
	sec = (*top)->next;
	last = ft_get_last_node(*top);
	(*top)->next = NULL;
	(*top)->prev = last;
	last->next = *top;
	sec->prev = NULL;
	*top = sec;
}

void	ra(t_node **stack_a, int print)
{
	ft_rotate(stack_a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_node **stack_b, int print)
{
	ft_rotate(stack_b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}
