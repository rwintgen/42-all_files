/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:33:34 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/30 15:27:42 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_node **src, t_node **dst)
{
	t_node	*src_sec;

	if (!(*src))
		return ;
	src_sec = (*src)->next;
	if (src_sec)
		src_sec->prev = NULL;
	(*src)->next = *dst;
	if (*dst)
		(*dst)->prev = *src;
	*dst = *src;
	*src = src_sec;
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}
