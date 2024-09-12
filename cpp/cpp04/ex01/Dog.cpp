/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:06:07 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:16:10 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = copy.getType(void);
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
		_type = copy.getType(void);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof woof!" << std::endl;
}

void	Dog::addIdea(std::string newIdea)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_brain->getIdea(i) == "")
		{
			this->_brain->setIdea(i, newIdea);
			return ;
		}
	}
	std::cout << "Dog's brain is full" << std::endl;
}

void	Dog::printAllIdeas(void) const
{
	std::cout << "What's happening in the dogs' brain:" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (this->_brain->getIdea(i) != "")
			std::cout << "Idea " << i << ": " << this->_brain->getIdea(i) << std::endl;
	}
}
