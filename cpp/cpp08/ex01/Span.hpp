/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:47:06 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:34:22 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class	Span
{
	public:
		Span(unsigned int n);
		Span(const Span &other);
		~Span(void);

		Span	&operator=(const Span &src);
		
		void	addNumber(int n);
		long	shortestSpan(void);
		long	longestSpan(void);
		void	addRandomNumbers(unsigned int span);

	private:
		unsigned int	_size;
		unsigned int	_id;
		long int		*_numbers;
};

#endif