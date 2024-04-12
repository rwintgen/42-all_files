/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:33:34 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/30 15:27:16 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_node **top)
{
	t_node	*sec;
	t_node	*thr;

	if (!(*top) || !((*top)->next))
		return ;
	sec = (*top)->next;
	thr = sec->next;
	(*top)->prev = sec;
	(*top)->next = thr;
	sec->prev = NULL;
	sec->next = *top;
	if (thr)
		thr->prev = *top;
	*top = sec;
}

void	sa(t_node **stack_a, int print)
{
	ft_swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_node **stack_b, int print)
{
	ft_swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}
