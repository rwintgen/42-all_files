/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 05:12:03 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/22 16:10:10 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int isbuiltin(char *cmd)
{
	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		return (1);
	else if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		return (1);
	else if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
		return (1);
	else if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		return (1);
	else if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		return (1);
	else if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		return (1);
	else if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0)
		return (1);
	return (0);
}
