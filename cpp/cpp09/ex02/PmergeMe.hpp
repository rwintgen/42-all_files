/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:42:55 by romain            #+#    #+#             */
/*   Updated: 2024/09/09 12:41:09 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
# include <stdexcept>
# include <deque>
# include <sstream>
# include <cctype>

class PmergeMe
{
	public:
		PmergeMe(std::string const &str);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();

		PmergeMe	&operator=(PmergeMe const &src);

		void	sortVector(void);
		void	sortDeque(void);

		void	printVector(void) const;
		void	printDeque(void) const;

	private:
		std::string			_input;
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		bool	isValidInput(std::string const &str);
		void	convertToVector(void);
		void	convertToDeque(void);
};

template <typename Container>
void convertToContainer(const std::string &input, Container &container);

template <typename Container>
void fordJohnsonSort(Container &container);

template <typename Container>
void printContainer(const Container &container);

# include "PmergeMe.tpp"

#endif