/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:48:42 by deymons           #+#    #+#             */
/*   Updated: 2024/05/13 19:22:54 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// prints arg list
void	print_t_arg_struct(t_arg *data)
{
	t_arg	*ptr;

	ptr = data;
	while (ptr)
	{
		printf("arg: \"%s\" type: %d\n", ptr->str_command, ptr->type);
		ptr = ptr->next;
	}
}

// prints cmd list
void	print_t_cmd_struct(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 1;
	while (cmd)
	{
		j = 0;
		printf("\ncommand number %d ", i);
		if (cmd->is_builtin == true)
			printf("- builtin: ");
		else
			printf("- not builtin: ");
		while (cmd->cmd_and_args[j])
		{
			if (j == 0)
				printf("%s\n", cmd->cmd_and_args[j]);
			else
				printf("arg %d: %s\n", j, cmd->cmd_and_args[j]);
			j++;
		}
		printf("fd in: %d\n", cmd->input_fd);
		printf("fd out: %d\n\n", cmd->output_fd);
		cmd = cmd->next;
		i++;
	}
}
