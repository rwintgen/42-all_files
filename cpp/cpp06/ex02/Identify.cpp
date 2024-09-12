/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:25:28 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:30:09 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base	*generate(void)
{
	int	randomNum = rand() % 3;

	if (randomNum == 0)
		return (new A());
	else if (randomNum == 1)
		return (new B());
	else
		return (new C());
}

void	identifyPtr(Base *ptr)
{
	std::cout << "Pointer: ";
	if (dynamic_cast<A*>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identifyRef(Base &ref)
{
	std::cout << "Reference: ";
	try
	{
		A &a = dynamic_cast<A&>(ref);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(ref);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch(const std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(ref);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}
