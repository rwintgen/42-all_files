/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:43:49 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:13:16 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
		std::cout << "WrongAnimal default constructor called" << std::endl;

}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::swap(WrongAnimal &obj1, WrongAnimal &obj2)
{
	WrongAnimal	tmp = obj1;

	obj1 = obj2;
	obj2 = tmp;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	this->_type = copy._type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "*Wrong animal sound*" << std::endl;
}