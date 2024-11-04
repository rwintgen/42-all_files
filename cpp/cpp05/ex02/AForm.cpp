/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:36:14 by romain            #+#    #+#             */
/*   Updated: 2024/10/30 16:42:20 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const &name, int signGrade, int execGrade) \
: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (name.empty())
		throw AForm::EmptyNameException();
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Form " << _name << " created" << std::endl;
}

AForm::AForm(AForm const &copy) \
: _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade), _signed(copy._signed)
{
	std::cout << "Form " << _name << " created from copy constructor" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

AForm	&AForm::operator=(AForm const &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (_name);
}

int	AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (_execGrade);
}

bool	AForm::isSigned(void) const
{
	return (_signed);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	if (this->_signed)
		throw AForm::FormSignedException();
	_signed = true;
}

std::ostream	&operator<<(std::ostream &out, AForm const &form)
{
	out << "Form " << form.getName() << " is " \
		<< (form.isSigned() ? "" : "not ") << "signed";
	return (out);
}