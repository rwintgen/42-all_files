/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:57:16 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/30 15:15:48 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_tokenize(t_node *stack)
{
	int	index;
	int	median;

	if (!stack)
		return ;
	index = 0;
	median = (ft_stack_len(stack) / 2) + 1;
	while (stack)
	{
		stack->pos = index;
		if (index < median)
			stack->top_half = 1;
		else
			stack->top_half = 0;
		index++;
		stack = stack->next;
	}
}

void	ft_targetize_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*cursor_b;
	t_node	*target_node;
	long	closest_lo;

	while (stack_a)
	{
		cursor_b = stack_b;
		target_node = NULL;
		closest_lo = LONG_MIN;
		while (cursor_b)
		{
			if (stack_a->nb > cursor_b->nb && cursor_b->nb > closest_lo)
			{
				target_node = cursor_b;
				closest_lo = cursor_b->nb;
			}
			cursor_b = cursor_b->next;
		}
		if (closest_lo == LONG_MIN)
			target_node = ft_get_max_node(stack_b);
		stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

void	ft_targetize_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*cursor_a;
	t_node	*target_node;
	long	closest_hi;

	while (stack_b)
	{
		cursor_a = stack_a;
		target_node = NULL;
		closest_hi = LONG_MAX;
		while (cursor_a)
		{
			if (cursor_a->nb > stack_b->nb && cursor_a->nb < closest_hi)
			{
				target_node = cursor_a;
				closest_hi = cursor_a->nb;
			}
			cursor_a = cursor_a->next;
		}
		if (closest_hi == LONG_MAX)
			target_node = ft_get_min_node(stack_a);
		stack_b->target = target_node;
		stack_b = stack_b->next;
	}
}

void	ft_cost_analyze(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(stack_a);
	len_b = ft_stack_len(stack_b);
	while (stack_a)
	{
		if (stack_a->top_half)
			stack_a->cost = stack_a->pos;
		else
			stack_a->cost = len_a - stack_a->pos;
		if (stack_a->target->top_half)
			stack_a->cost += stack_a->target->pos;
		else
			stack_a->cost += len_b - stack_a->target->pos;
		stack_a = stack_a->next;
	}
}

void	ft_find_cheapest(t_node *stack)
{
	long	cheapest_v;
	t_node	*cheapest_n;

	cheapest_n = NULL;
	cheapest_v = LONG_MAX;
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->cost < cheapest_v)
		{
			cheapest_v = stack->cost;
			cheapest_n = stack;
		}
		stack->cheapest = 0;
		stack = stack->next;
	}
	cheapest_n->cheapest = 1;
}
