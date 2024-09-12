/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:06:35 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:16:10 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = copy.getType(void);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::swap(Cat &obj1, Cat &obj2)
{
	std::cout << "Cat swap called" << std::endl;
	std::swap(obj1._type, obj2._type);
}

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &copy)
		_type = copy.getType(void);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow meow!" << std::endl;
}

void	Cat::addIdea(std::string newIdea)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_brain->getIdea(i) == "")
		{
			this->_brain->setIdea(i, newIdea);
			return ;
		}
	}
	std::cout << "The cat's brain is full" << std::endl;
}

void	Cat::printAllIdeas(void) const
{
	std::cout << "What's happening in the cats' brain:" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (this->_brain->getIdea(i) != "")
			std::cout << "Idea " << i << ": " << this->_brain->getIdea(i) << std::endl;
	}
}
