/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:41:43 by rwintgen          #+#    #+#             */
/*   Updated: 2024/02/07 13:03:08 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_stack(t_node **stack)
{
	t_node	*curr;
	t_node	*tmp;

	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

void	ft_err_free(int err_id, t_node **stack)
{
	(void) stack;
	if (err_id != 1)
		write(2, "Error\n", 6);
	ft_free_stack(stack);
}

int	ft_err_dup(t_node *stack, int nb)
{
	while (stack)
	{
		if (stack->nb == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_err_syntax(char *nb)
{
	int	i;

	i = 0;
	if (nb[i] != '-' && nb[i] != '+' && !ft_isdigit(nb[i]))
		return (1);
	else if ((nb[i] == '-' || nb[i] == '+') && !ft_isdigit(nb[i + 1]))
		return (1);
	nb++;
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (1);
		i++;
	}
	if (i > 10)
		return (1);
	return (0);
}
