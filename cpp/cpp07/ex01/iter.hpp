/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:00:24 by romain            #+#    #+#             */
/*   Updated: 2024/08/21 18:13:22 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename A, typename Foo>
void	iter(A *array, size_t size, Foo function)
{
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

#endif