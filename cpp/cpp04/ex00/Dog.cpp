/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:06:07 by romain            #+#    #+#             */
/*   Updated: 2024/09/26 12:17:46 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = copy.getType();
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::swap(Dog &obj1, Dog &obj2)
{
	std::cout << "Dog swap called" << std::endl;
	std::swap(obj1._type, obj2._type);
}

Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		_type = copy.getType();
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof woof!" << std::endl;
}
