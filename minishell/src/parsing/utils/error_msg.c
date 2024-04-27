/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:25:48 by rwintgen          #+#    #+#             */
/*   Updated: 2024/04/27 12:49:29 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	err_msg_syntax(char *msg, int ret)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	return (ret);
}
