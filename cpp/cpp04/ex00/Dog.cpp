/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:06:07 by romain            #+#    #+#             */
/*   Updated: 2024/08/13 12:06:17 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}
void	Dog::makeSound(void) const
{
	std::cout << "Woof woof!" << std::endl;
}