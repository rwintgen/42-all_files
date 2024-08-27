/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:59:08 by romain            #+#    #+#             */
/*   Updated: 2024/08/27 10:59:16 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AScalarConverter.hpp"

template <typename T>
void printDecimals(T value, unsigned int type)
{
	T number = type ? static_cast<double>(value) : static_cast<float>(value);
	int integer = static_cast<int>(number);
	int decimals = static_cast<int>((number - integer) * 10 + 0.5);
	std::cout << integer << "." << decimals;
}