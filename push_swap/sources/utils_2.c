/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:52:06 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/29 15:03:19 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_get_max_node(t_node *stack)
{
	int		max;
	t_node	*max_node;

	max = INT_MIN;
	max_node = NULL;
	while (stack)
	{
		if (stack->nb > max)
		{
			max = stack->nb;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_node	*ft_get_min_node(t_node *stack)
{
	int		min;
	t_node	*min_node;

	min = INT_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->nb < min)
		{
			min = stack->nb;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_node	*ft_get_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_node	*ft_get_cheapest(t_node *stack)
{
	while (stack && !(stack->cheapest))
		stack = stack->next;
	return (stack);
}
