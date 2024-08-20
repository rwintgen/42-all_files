/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:36:14 by romain            #+#    #+#             */
/*   Updated: 2024/08/20 15:06:18 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, int signGrade, int execGrade) \
: _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (name.empty())
		throw Form::EmptyNameException();
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << _name << " created" << std::endl;
}

Form::Form(Form const &copy) \
: _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade), _signed(copy._signed)
{
	std::cout << "Form " << _name << " created from copy constructor" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

Form	&Form::operator=(Form const &src)
{
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

std::string	Form::getName() const
{
	return (_name);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecGrade() const
{
	return (_execGrade);
}

bool	Form::isSigned() const
{
	return (_signed);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	if (this->_signed)
		throw Form::FormSignedException();
	_signed = true;
}

std::ostream	&operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " is " \
		<< (form.isSigned() ? "" : "not ") << "signed";
	return (out);
}