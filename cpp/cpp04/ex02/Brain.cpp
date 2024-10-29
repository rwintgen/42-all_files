/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:04:46 by romain            #+#    #+#             */
/*   Updated: 2024/10/29 16:26:58 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	this->_ideas = new std::string[100];
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	if (!copy._ideas)
	{
		this->_ideas = NULL;
		return ;
	}
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	if (this->_ideas)
		delete [] this->_ideas;
}

Brain	&Brain::operator=(Brain copy)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &copy)
	{
		for (unsigned int i = 0; i < 100; i++)
		{
			this->_ideas[i] = copy._ideas[i];
		}
	}
	return (*this);
}

std::string Brain::getIdea(unsigned int index) const
{
	if (index > 99)
	{
		std::cout << "Can't get idea " << index << std::endl;
		return "";
	}
	return this->_ideas[index];
}

void Brain::setIdea(unsigned int index, std::string idea)
{
	if (index > 99)
	{
		std::cout << "Can't set idea " << index << std::endl;
		return;
	}
	this->_ideas[index] = idea;
}
