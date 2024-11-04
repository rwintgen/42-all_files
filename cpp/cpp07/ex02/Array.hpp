/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:21:08 by romain            #+#    #+#             */
/*   Updated: 2024/11/04 11:46:18 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &src);
		~Array(void);

		Array	&operator=(Array const &src);
		T		&operator[](unsigned int i);
		const T	&operator[](unsigned int i) const;

		unsigned int	size(void) const;

	private:
		T				*_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif