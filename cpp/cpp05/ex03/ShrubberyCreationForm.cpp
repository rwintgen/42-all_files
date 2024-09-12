/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:12:15 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:27:53 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) \
: AForm("SCF", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm " << AForm::getName(void) << " created"  << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) \
: AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm " << AForm::getName(void) << " destroyed"  << std::endl;
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
	if (this->isSigned(void) == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade(void) > this->getExecGrade(void))
		throw AForm::GradeTooLowException();
	std::ofstream	file(this->_target + "_shrubbery");
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

AForm	*ShrubberyCreationForm::create(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}
