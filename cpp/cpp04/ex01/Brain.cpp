/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:04:46 by romain            #+#    #+#             */
/*   Updated: 2024/08/13 18:22:49 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
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

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	if (this->_ideas)
		delete [] this->_ideas;
}

void	Brain::swap(Brain &obj1, Brain &obj2)
{
	std::swap(obj1._ideas, obj2._ideas);
}

Brain	&Brain::operator=(Brain copy)
{
	std::cout << "Brain assignation operator called" << std::endl;
	Brain::swap(*this, copy);
	return (*this);
}

std::string	*Brain::getIdeas(void) const
{
	return (this->_ideas);
}

void	Brain::setIdeas(std::string *ideas)
{
	if (this->_ideas)
		delete [] this->_ideas;
	this->_ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = ideas[i];
}
