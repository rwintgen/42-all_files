/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:20:26 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/30 15:14:09 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_data_a(t_node *stack_a, t_node *stack_b)
{
	ft_tokenize(stack_a);
	ft_tokenize(stack_b);
	ft_targetize_a(stack_a, stack_b);
	ft_cost_analyze(stack_a, stack_b);
	ft_find_cheapest(stack_a);
}

void	ft_init_data_b(t_node *stack_a, t_node *stack_b)
{
	ft_tokenize(stack_a);
	ft_tokenize(stack_b);
	ft_targetize_b(stack_a, stack_b);
}

void	ft_bring_to_top(t_node **a, t_node **b, t_node *top_a, t_node *top_b)
{
	while (*a != top_a)
	{
		if (top_a->top_half)
			ra(a, 1);
		else
			rra(a, 1);
	}
	while (*b != top_b)
	{
		if (top_b->top_half)
			rb(b, 1);
		else
			rrb(b, 1);
	}
}

void	ft_transfer_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = ft_get_cheapest(*stack_a);
	if (cheapest->top_half && cheapest->target->top_half)
	{
		while (*stack_a != cheapest && *stack_b != cheapest->target)
			rr(stack_a, stack_b);
		ft_tokenize(*stack_a);
		ft_tokenize(*stack_b);
	}
	else if (!(cheapest->top_half) && !(cheapest->target->top_half))
	{
		while (*stack_a != cheapest && *stack_b != cheapest->target)
			rrr(stack_a, stack_b);
		ft_tokenize(*stack_a);
		ft_tokenize(*stack_b);
	}
	ft_bring_to_top(stack_a, stack_b, cheapest, cheapest->target);
	pb(stack_a, stack_b);
}

void	ft_transfer_to_a(t_node **stack_a, t_node **stack_b)
{
	ft_bring_to_top(stack_a, stack_b, (*stack_b)->target, *stack_b);
	pa(stack_b, stack_a);
}
