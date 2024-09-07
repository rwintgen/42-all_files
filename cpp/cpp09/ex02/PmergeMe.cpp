/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:40:16 by romain            #+#    #+#             */
/*   Updated: 2024/09/07 12:35:43 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string const &str)
{
	if (!isValidInput(str))
		throw std::invalid_argument("Invalid input");
	// initialize attributes here
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		// copy attributes here
	}
	return (*this);
}

bool	PmergeMe::isValidInput(std::string const &str)
{
	if (str.empty())
		return (false);
	for (int i = 0; i < str.size(); i++)
		if (!std::isdigit(str[i]) && !std::isspace(str[i]))
			return (false);
	this->_input = str;
	return (true);
}

