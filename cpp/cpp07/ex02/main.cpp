/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:05:01 by romain            #+#    #+#             */
/*   Updated: 2024/11/04 11:47:46 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int>	arrayInt(10);
    Array<char>	arrayChar(10);

	for (unsigned int i = 0; i < arrayInt.size(); i++)
		arrayInt[i] = i;

	for (unsigned int i = 0; i < arrayChar.size(); i++)
		arrayChar[i] = i + 65;
	
	for (unsigned int i = 0; i < arrayInt.size(); i++)
		std::cout << arrayInt[i] << " ";
	std::cout << std::endl;

	for (unsigned int i = 0; i < arrayChar.size(); i++)
		std::cout << arrayChar[i] << " ";
	std::cout << std::endl;

	outOfBounds(arrayInt, 4);
	outOfBounds(arrayChar, 4);
	outOfBounds(arrayInt, 42);
	outOfBounds(arrayChar, 42);
	outOfBounds(arrayChar, -42);
	outOfBounds(arrayChar, -42);

	return (0);
}