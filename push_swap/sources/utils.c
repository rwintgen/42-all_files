/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:40:09 by rwintgen          #+#    #+#             */
/*   Updated: 2024/02/07 13:01:02 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_split(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	ft_stack_len(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	ft_stack_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nb >= stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_lst_append(t_node **stack, int nb)
{
	t_node	*last_node;
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->nb = nb;
	if (!(*stack))
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		last_node = ft_get_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	ft_init_stack_a(t_node **stack_a, char **argv)
{
	long	nb;
	int		i;

	if (!(*argv))
		ft_err_free(6, stack_a);
	i = 0;
	while (argv[i])
	{
		if (ft_err_syntax(argv[i]))
		{
			ft_err_free(2, stack_a);
			break ;
		}
		nb = ft_atol(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX || ft_err_dup(*stack_a, nb))
		{
			ft_err_free(3, stack_a);
			break ;
		}
		ft_lst_append(stack_a, nb);
		i++;
	}
}
