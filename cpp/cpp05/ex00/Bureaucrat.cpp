/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:57:16 by romain            #+#    #+#             */
/*   Updated: 2024/08/20 13:51:59 by romain           ###   ########.fr       */
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
	std::cout << "Bureaucrat " << this->_name << " created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

std::string const	&Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooLowException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade++;
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}