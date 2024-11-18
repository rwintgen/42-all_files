/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:42:55 by romain            #+#    #+#             */
/*   Updated: 2024/11/15 14:02:11 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <iomanip>
# include <vector>
# include <algorithm>
# include <string>
# include <stdexcept>
# include <deque>
# include <sstream>
# include <cctype>
# include <climits>

class PmergeMe
{
	public:
		PmergeMe(std::string const &str);
		PmergeMe(PmergeMe const &src);
		~PmergeMe();

		PmergeMe	&operator=(PmergeMe const &src);

		double	sortVector(void);
		double	sortDeque(void);

		void	printVector(bool before) const;
		void	printDeque(bool before) const;

		static int	stringToInt(const std::string &str);

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
void printContainer(const Container &container);

template <typename Container>
std::vector<Container> createPairs(Container &nums);

template <typename Container>
std::vector<Container> sortPairs(std::vector<Container> &splitArray);

template <typename Container>
void insert(Container pair, std::vector<Container> &pairsArray, int len);

template <typename Container>
void insertionSortPairs(std::vector<Container> &A, int len);

template <typename Container>
void sortByBiggestElem(std::vector<Container> &sortedArray);

template <typename Container>
Container getJacobSequence(const Container &array);

template <typename Container>
Container createJacobSeq(std::vector<Container> &SPA, int straggler);

template <typename Container>
void fordJohnsonSort(Container &nums);

# include "PmergeMe.tpp"

#endif