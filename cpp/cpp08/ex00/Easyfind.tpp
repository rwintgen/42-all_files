/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:49:17 by romain            #+#    #+#             */
/*   Updated: 2024/08/28 10:04:42 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Easyfind.hpp"

template <typename T>
int	easyfind(T container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::runtime_error("not found");
	return (target);
}
