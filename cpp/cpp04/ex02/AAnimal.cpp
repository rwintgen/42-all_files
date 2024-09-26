/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:27:31 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/26 13:35:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "AAnimal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	_type = copy.getType();}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

void	AAnimal::swap(AAnimal &obj1, AAnimal &obj2)
{
	std::cout << "AAnimal swap called" << std::endl;
	std::swap(obj1._type, obj2._type);
}

AAnimal	&AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this != &copy)
		_type = copy.getType();
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::setType(std::string type)
{
	this->_type = type;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "*Random animal sound*" << std::endl;
}
