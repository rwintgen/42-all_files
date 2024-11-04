/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:47:04 by romain            #+#    #+#             */
/*   Updated: 2024/11/04 16:33:07 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
}

Span::Span(unsigned int n) : _id(0)
{
	std::cout << "Default constructor called" << std::endl;
	if (n == 0 || n > INT_MAX)
		throw std::invalid_argument("Invalid size");
	this->_size = n;
	this->_numbers = new long int[n];
}

Span::Span(const Span &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Span::~Span(void)
{
	std::cout << "Destructor called" << std::endl;
	delete[] this->_numbers;
}

Span	&Span::operator=(Span const &src)
{
	if (&src != this)
	{
		this->_size = src._size;
		this->_id = src._id;
		this->_numbers = new long int[this->_size];
		for (unsigned int i = 0; i < this->_id; i++)
			this->_numbers[i] = src._numbers[i];
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_id >= this->_size)
		throw std::invalid_argument("No more space");

	this->_numbers[this->_id++] = n;
}

long	Span::shortestSpan(void)
{
	if (this->_id < 2)
		throw std::invalid_argument("Not enough numbers");

	std::sort(this->_numbers, this->_numbers + this->_id);

	long min = LONG_MAX;

	for (unsigned int i = 1; i < this->_id; i++)
		min = std::min(min, this->_numbers[i] - this->_numbers[i - 1]);

	return (min);
}

long	Span::longestSpan(void)
{
	if (this->_id < 2)
		throw std::invalid_argument("Not enough numbers");

	std::sort(this->_numbers, this->_numbers + this->_id);

	return (this->_numbers[this->_id - 1] - this->_numbers[0]);
}

void Span::addRandomNumbers(unsigned int span)
{
	if (this->_id + span > this->_size)
		throw std::invalid_argument("No more space");

	std::srand(std::time(0));

	for (unsigned int i = 0; i < span; i++)
		this->_numbers[this->_id++] = std::rand();

	for (unsigned int i = 0; i < this->_id; i++)
		std::cout << this->_numbers[i] << " ";
}
