/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:57:39 by romain            #+#    #+#             */
/*   Updated: 2024/11/04 14:21:16 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array(void) : _array(new T), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	for (unsigned int i = 0; i < n; i++)
		_array[i] = T();
}

template <typename T>
Array<T>::Array(Array const &src) : _array(new T[src.size()]), _size(src.size())
{
	for (unsigned int i = 0; i < src.size(); i++)
		_array[i] = src[i];
}

template <typename T>
Array<T>::~Array(void)
{
	if (this->_array)
		delete [] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &src)
{
	if (this != &src)
	{
		delete [] this->_array;
		_array = new T[src.size()];
		_size = src.size();
		for (unsigned int i = 0; i < src.size(); i++)
			_array[i] = src[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range("Out of range");
	return (_array[i]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw std::out_of_range("Out of range");
	return (_array[i]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
void	outOfBounds(Array<T> &array, int i)
{
	try
	{
		std::cout << array[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
