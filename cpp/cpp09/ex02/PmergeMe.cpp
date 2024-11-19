/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:40:16 by romain            #+#    #+#             */
/*   Updated: 2024/11/19 13:15:31 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string const &str)
{
	if (!isValidInput(str))
		throw std::invalid_argument("Invalid input");
	this->_vec.clear();
	this->_deq.clear();
	convertToVector();
	convertToDeque();
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		this->_input = src._input;
		this->_vec = src._vec;
		this->_deq = src._deq;
	}
	return (*this);
}

bool	PmergeMe::isValidInput(std::string const &str)
{
	if (str.empty())
		return (false);

	for (size_t i = 0; i < str.size(); i++)
		if (!std::isdigit(str[i]) && !std::isspace(str[i]))
			return (false);

	this->_input = str;
	return (true);
}

void	PmergeMe::convertToVector(void)
{
	convertToContainer(this->_input, this->_vec);
}

void	PmergeMe::convertToDeque(void)
{
	convertToContainer(this->_input, this->_deq);
}

double	PmergeMe::sortVector(void)
{
	clock_t start = clock();

	fordJohnsonSort(this->_vec);

	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;

	return (elapsed);
}

double	PmergeMe::sortDeque(void)
{
	clock_t start = clock();

	fordJohnsonSort(this->_deq);

	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;

	return (elapsed);
}

void PmergeMe::printVector(bool before) const
{
	std::cout << (before ? "Before: " : "After: ");
	printContainer(this->_vec);
}

void PmergeMe::printDeque(bool before) const
{
	std::cout << (before ? "Before: " : "After: ");
	printContainer(this->_deq);
}

int PmergeMe::stringToInt(const std::string &str)
{
    char	*end;
    long	number = std::strtol(str.c_str(), &end, 10);

    if (*end != '\0' || number > INT_MAX || number < INT_MIN)
        throw std::runtime_error("Invalid input");

    return (static_cast<int>(number));
}