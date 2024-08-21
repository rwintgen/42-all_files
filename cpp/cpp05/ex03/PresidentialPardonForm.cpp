/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:57:20 by romain            #+#    #+#             */
/*   Updated: 2024/08/21 13:15:01 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) \
: AForm("PPF", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm " << AForm::getName() << " created"  << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) \
: AForm(copy), _target(copy._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << AForm::getName() << " destroyed"  << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

AForm	*PresidentialPardonForm::create(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}
