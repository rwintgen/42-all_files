/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:20:35 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/30 15:14:30 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_easy_sort(t_node **stack_a, int stack_len)
{
	t_node	*big;

	big = NULL;
	if (stack_len == 2)
		sa(stack_a, 1);
	else
	{
		big = ft_get_max_node(*stack_a);
		if (big == *(stack_a))
			ra(stack_a, 1);
		else if (big == (*stack_a)->next)
			rra(stack_a, 1);
		if ((*stack_a)->nb > (*stack_a)->next->nb)
			sa(stack_a, 1);
	}
}

static void	ft_order(t_node **stack)
{
	t_node	*min_node;

	if (!stack)
		return ;
	ft_tokenize(*stack);
	min_node = ft_get_min_node(*stack);
	while (*stack != min_node)
	{
		if (min_node->top_half)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}

void	ft_hard_sort(t_node **stack_a, t_node **stack_b)
{
	unsigned int	len_a;
	unsigned int	len_b;

	len_a = ft_stack_len(*stack_a);
	len_b = ft_stack_len(*stack_b);
	while (len_a > 3 && len_b < 2 && !ft_stack_sorted(*stack_a))
	{
		pb(stack_a, stack_b);
		len_a--;
		len_b++;
	}
	while (len_a > 3 && !ft_stack_sorted(*stack_a))
	{
		ft_init_data_a(*stack_a, *stack_b);
		ft_transfer_to_b(stack_a, stack_b);
		len_a--;
	}
	ft_easy_sort(stack_a, ft_stack_len(*stack_a));
	while (*stack_b)
	{
		ft_init_data_b(*stack_a, *stack_b);
		ft_transfer_to_a(stack_a, stack_b);
	}
	ft_order(stack_a);
}
