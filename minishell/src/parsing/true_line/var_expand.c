/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:38:25 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/26 18:17:59 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

///////// TODO //////////
// x = variable expansion
// n = no variable expansion
//
// to test: 
/*
echo "'$USER'" -> x														=> OK
echo '"$USER"' -> nx													=> OK
echo "'"$USER"'" -> x													=> OK
echo '"'$USER'"' -> x													=> OK
echo "'"'$USER'"'" -> nx												=> OK
echo '"'"$USER"'"' -> x													=> OK
echo "$USER" '$USER' -> x, nx											=> OK
echo '$USER' "$USER" -> nx, x											=> OK
echo "$USER" '$USER' "$USER" '$USER' -> x, nx, x, nx					=> OK
echo '$USER' "$USER" '$USER' "$USER" -> nx, x, nx, x					=> OK
echo "'$USER"' '"$USER'" -> 'rwintgen rwintgen'							=> OK
echo "'$USER'" '"$USER"' -> 'rwintgen' "$USER"							=> OK
echo "'"'"'$USER'"'"'" '"'"'"$USER"'"'"' -> '"rwintgen"' "'rwintgen'"	=> OK
*/
/////////////////////////

bool	is_valid_var(char *input, int dollar)
{
	int	sq;
	int	dq;
	int	i;

	sq = 0;
	dq = 0;
	i = 0;
	while (input[i] && i < dollar)
	{
		if (input[i] == '\'' && !dq)
			sq = !sq;
		if (input[i] == '"' && !sq)
			dq = !dq;
		i++;
	}
	if (sq)
		return (false);
	// printf("is_valid_var\n"); // DEBUG
	return (true);
}

char	*var_expand(char *input, t_envp *envp, int exit_code)
{
	int	i;
	int	len;

	// printf("before expansion:\t%s\n", input); // DEBUG
	len = ft_strlen(input);
	i = 0;
	while (input[i])
	{
		if (input[i] == '$' && is_valid_var(input, i))
			input = var_replace(input, &i, envp, exit_code);
		if (i < len - 1)
			i++;
		else
			break ;
	}
	return (input);
}

char	*var_replace(char *input, int *i, t_envp *envp, int exit_code)
{
	int		key_len;
	char	*key;
	char	*var;
	char	*tmp;

	if (!input[*i + 1] || input[*i + 1] == '$' || input[*i + 1] == ' ')
		return (input);
	if (input[*i + 1] == '?')
	{
		tmp = ft_itoa(exit_code);
		input = ft_strrep(input, "$?", tmp);
		free(tmp);
		*i += 1;
	}
	else
	{
		key_len = get_key_len(input, *i);
		key = ft_substr(input, *i, key_len);
		// printf("key:\t%s\n", key); // DEBUG
		var = get_var(key, envp);
		// printf("var:\t%s\n", var); // DEBUG
		if (var)
			input = ft_strrep(input, key, var);
		else
			input = ft_strrep(input, key, "");
		*i += key_len;
	}
	return (input);
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
		if (ft_strncmp(envp_key, &key[1], ft_strlen(key)) == 0)
		{
			free(envp_key);
			return (envp->envar + i + 1);
		}
		free(envp_key);
		envp = envp->next;
	}
	return (NULL);
}

int	get_key_len(char *input, int i)
{
	int		key_len;

	key_len = 1;
	while (input[i + key_len] && ft_isalnum(input[i + key_len]))
		key_len++;
	return (key_len);
}
