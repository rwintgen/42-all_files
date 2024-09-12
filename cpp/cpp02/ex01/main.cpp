/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:41:15 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 12:14:26 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt(void) << " as integer" << std::endl;
	std::cout << "b is " << b.toInt(void) << " as integer" << std::endl;
	std::cout << "c is " << c.toInt(void) << " as integer" << std::endl;
	std::cout << "d is " << d.toInt(void) << " as integer" << std::endl;
	
	return (0);
}