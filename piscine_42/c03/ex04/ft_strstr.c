/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:48:42 by rwintgen          #+#    #+#             */
/*   Updated: 2023/09/28 10:56:31 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	istr;
	int	itf;

	istr = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[istr] != '\0')
	{
		itf = 0;
		if (str[istr] == to_find[0])
		{
			while (str[istr + itf] == to_find[itf] && to_find[itf] != '\0')
			{
				itf++;
			}
			if (to_find[itf] == '\0')
				return (&str[istr]);
		}
		istr++;
	}
	return (0);
}
