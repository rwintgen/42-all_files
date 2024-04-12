/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:24:20 by rwintgen          #+#    #+#             */
/*   Updated: 2024/01/25 13:54:52 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		ft_err_free(1, &stack_a);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		ft_init_stack_a(&stack_a, argv);
		ft_free_split(argv);
	}
	else
		ft_init_stack_a(&stack_a, argv + 1);
	if (!ft_stack_sorted(stack_a))
	{
		if (ft_stack_len(stack_a) < 4)
			ft_easy_sort(&stack_a, ft_stack_len(stack_a));
		else
			ft_hard_sort(&stack_a, &stack_b);
	}
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
