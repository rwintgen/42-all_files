/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:06:07 by romain            #+#    #+#             */
/*   Updated: 2024/10/29 16:14:39 by rwintgen         ###   ########.fr       */
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
