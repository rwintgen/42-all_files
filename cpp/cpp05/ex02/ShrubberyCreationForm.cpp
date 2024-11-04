/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:12:15 by romain            #+#    #+#             */
/*   Updated: 2024/10/30 16:45:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) \
: AForm("SCF", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm " << AForm::getName() << " created"  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) \
: AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm " << AForm::getName() << " destroyed"  << std::endl;
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

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::ofstream	file((this->_target + "_shrubbery").c_str());
	if (file.is_open() == false)
		throw AForm::FileNotOpenException();
	else
	{
		file << "       _-_       " << std::endl;
		file << "    /~~   ~~\\    " << std::endl;
		file << " /~~         ~~\\ " << std::endl;
		file << "{               }" << std::endl;
		file << " \\  _-     -_  / " << std::endl;
		file << "   ~  \\ //  ~   " << std::endl;
		file << "_- -   | | _- _  " << std::endl;
		file << "  _ -  | |   -_  " << std::endl;
		file << "      // \\      " << std::endl;
		file.close();
	}
}
