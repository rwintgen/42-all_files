/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:00:24 by romain            #+#    #+#             */
/*   Updated: 2024/11/04 09:45:03 by rwintgen         ###   ########.fr       */
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

// template <typename T>
// void print(T &elem)
// {
//     std::cout << elem << " ";
// }

#endif