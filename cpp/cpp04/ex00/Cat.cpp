/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:06:35 by romain            #+#    #+#             */
/*   Updated: 2024/08/13 12:07:06 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}
void	Cat::makeSound(void) const
{
	std::cout << "Meow meow!" << std::endl;
}
