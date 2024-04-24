/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:51:56 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/24 11:35:07 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_replace(char *str, char *old, char *new)
{
    char	*result;
    char	*ptr;
    char	*tmp;
    int		count;

    count = 0;
    ptr = str;
    while ((ptr = ft_strnstr(ptr, old, ft_strlen(ptr))) != NULL)
    {
        count++;
        ptr += ft_strlen(old);
    }
    result = (char *)malloc(ft_strlen(str) + (ft_strlen(new) - ft_strlen(old)) * count + 1);
    if (!result)
        return (NULL);
    ptr = result;
    while (*str)
    {
        if ((tmp = ft_strnstr(str, old, ft_strlen(str))) == str)
        {
            ft_strlcpy(ptr, new, ft_strlen(new) + 1); // Use ft_strlen(new) instead of ft_strlen(ptr)
            ptr += ft_strlen(new);
            str += ft_strlen(old);
        }
        else
            *ptr++ = *str++;
    }
    *ptr = '\0';
    return (result);
}
