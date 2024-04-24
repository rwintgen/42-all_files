/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:38:25 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/24 16:48:52 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*var_expand(char *input, t_envp *envp, int exit_code)
{
	int		i;
	int		single_quote;
	int		double_quote;
	char	*var;
	char	*key;

	i = 0;
	single_quote = 0;
	double_quote = 0;
	while (input[i])
	{
		if (input[i] == '"')
			double_quote++;
		else if (input[i] == '\'')
			single_quote++;
		if (input[i] == '$' && single_quote % 2 == 0)
		{
			key = var_getkey(input, i + 1);
			var = var_export(input, i + 1, envp);
			//printf("\ninput: %s\nkey: %s\nvar: %s\n", input, key, var);
			if (var && ft_strlen(var) > 0)
			{
				input = ft_str_replace(input, key, var);
				//printf("input: %s\n", input);
			}
			else if (input[i + 1] && input[i + 1] == '?')
				input = ft_str_replace(input, key, ft_itoa(exit_code));
			else
				input = ft_str_replace(input, key, "");
		}
		i++;
	}
	return (input);
}

char	*var_getkey(char *str, int i)
{
	char	*key;
	int		j;

	j = i;
	while (str[j] && ft_isalpha(str[j]))
		j++;
	if (str[j] == '?')
		j++;
	key = ft_substr(str, i - 1, j - i + 1);
	return (key);
}

char	*var_export(char *str, int i, t_envp *envp)
{
	char	*var;
	char	*key;
	int		j;

	j = i;
	while (str[j] && str[j] != ' ' && str[j] != '$')
		j++;
	key = ft_substr(str, i, j - i);
	var = get_var(key, envp);
	free(key);
	return (var);

}

char	*get_var(char *key, t_envp *envp)
{
	char	*envp_key;
	int		i;

	while (envp)
	{
		i = 0;
		while (envp->envar[i] && envp->envar[i] != '=')
			i++;
		envp_key = ft_substr(envp->envar, 0, i);
		if (ft_strncmp(envp_key, key, ft_strlen(key)) == 0)
		{
			free(envp_key);
			return (envp->envar + i + 1);
		}
		free(envp_key);
		envp = envp->next;
	}
	return (NULL);
}
