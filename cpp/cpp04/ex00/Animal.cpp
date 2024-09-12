/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:45:57 by romain            #+#    #+#             */
/*   Updated: 2024/08/13 12:35:33 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	_type = copy.getType(void);}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::swap(Animal &obj1, Animal &obj2)
{
	std::cout << "Animal swap called" << std::endl;
	std::swap(obj1._type, obj2._type);
}
Animal	&Animal::operator=(const Animal &copy)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &copy)
		_type = copy.getType(void);
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(std::string type)
{
	this->_type = type;
}

void	Animal::makeSound(void) const
{
	std::cout << "*Random animal sound*" << std::endl;
}
