/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:42:55 by romain            #+#    #+#             */
/*   Updated: 2024/09/07 12:59:17 by romain           ###   ########.fr       */
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

class	PmergeMe
{
	public:
		PmergeMe(std::string const &str);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();

		PmergeMe	&operator=(PmergeMe const &src);

		void	sortNumbers(void);
		void	printResult(void) const;

	private:
		std::string			_input;
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		// Step 1 - check that argv contains valid numbers
		bool				isValidInput(std::string const &str);
		// Step 2.1 - convert argv into a vector of integers
		std::vector<int>	convertToVector(std::string const &str);
		// Step 2.2 - convert argv into a deque of integers
		std::deque<int>		convertToDeque(std::string const &str);
		// Step 3 - sorting algorithm
		
};

#endif