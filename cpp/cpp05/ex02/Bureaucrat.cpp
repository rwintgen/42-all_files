/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:57:16 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:24:53 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	if (name.empty())
		throw Bureaucrat::EmptyNameException();
	this->_grade = grade;
	std::cout << "Bureaucrat " << this->_name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat " << this->_name << " created from copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName(void) << ", bureaucrat grade " << bureaucrat.getGrade(void);
	return (out);
}

void	Bureaucrat::signForm(AForm &form)
{
	if (this->_grade > form.getSignGrade(void))
	{
		std::cout << this->getName(void) << " couldn't sign " << form.getName(void) << " because ";
		throw Bureaucrat::GradeTooLowException();
	}
	if (form.isSigned(void))
	{
		std::cout << this->getName(void) << " couldn't sign " << form.getName(void) << " because ";
		throw AForm::FormSignedException();
	}
	std::cout << this->getName(void) << " signed " << form.getName(void) << std::endl; 
	form.beSigned(*this);
}

void	Bureaucrat::executeForm(const AForm &form)
{
	if (this->_grade > form.getExecGrade(void))
	{
		std::cout << this->getName(void) << " couldn't execute " << form.getName(void) << " because ";
		throw Bureaucrat::GradeTooLowException();
	}
	if (!form.isSigned(void))
	{
		std::cout << this->getName(void) << " couldn't execute " << form.getName(void) << " because ";
		throw AForm::FormNotSignedException();
	}
	std::cout << this->getName(void) << " executed " << form.getName(void) << std::endl;
	form.execute(*this);
}
