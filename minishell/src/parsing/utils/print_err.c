/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:50:15 by rwintgen          #+#    #+#             */
/*   Updated: 2024/05/24 14:36:29 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err(char *s1, char *s2, char *s3, char *s4)
{
	char	*result;

	result = NULL;
	if (!s1)
		return ;
	if (s2)
		result = ft_strjoin(s1, s2);
	if (s3)
		result = ft_strjoin(result, s3);
	if (s4)
		result = ft_strjoin(result, s4);
	write(STDERR_FILENO, result, ft_strlen(result));
	ft_putstr_fd("\n", STDERR_FILENO);
	free(result);
}
