/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:12:15 by romain            #+#    #+#             */
/*   Updated: 2024/08/20 16:25:04 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) \
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) \
: AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat)
{
	// Draw ascii tree
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}