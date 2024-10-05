/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:41:15 by romain            #+#    #+#             */
/*   Updated: 2024/10/05 16:31:00 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	// Fixed		a;
	// Fixed const	b(Fixed(5.05f) * Fixed(2));

	// std::cout << "Main tests:" << std::endl;
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;

	Fixed a(10);
	Fixed b(5);
	Fixed c(2.5f);

	// Arithmetic Operators
	std::cout << "Arithmetic Operators:" << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;
	std::cout << "a + c = " << (a + c) << std::endl;
	std::cout << "a - c = " << (a - c) << std::endl;
	std::cout << "a * c = " << (a * c) << std::endl;
	std::cout << "a / c = " << (a / c) << std::endl;

	// Comparison Operators
	std::cout << "\nComparison Operators:" << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;

	// Increment/Decrement Operators
	std::cout << "\nIncrement/Decrement Operators:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;

	// Min/Max Functions
	std::cout << "\nMin/Max Functions:" << std::endl;
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, c): " << Fixed::min(a, c) << std::endl;
	std::cout << "max(a, c): " << Fixed::max(a, c) << std::endl;

	return (0);
}