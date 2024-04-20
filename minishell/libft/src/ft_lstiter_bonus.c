/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangi <amalangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:21:01 by amalangi          #+#    #+#             */
/*   Updated: 2023/11/07 04:21:23 by amalangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;
	t_list	*nxt;

	if (!lst || !f)
		return ;
	tmp = lst;
	while (tmp)
	{
		nxt = tmp->next;
		f((void *)tmp->content);
		tmp = nxt;
	}
}
