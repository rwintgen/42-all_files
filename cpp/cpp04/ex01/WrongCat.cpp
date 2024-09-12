/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:43:57 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:16:08 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	_type = copy.getType(void);
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &copy)
		_type = copy.getType(void);
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "BLARGBLARFOUYABLARGAGAW" << std::endl;
}
