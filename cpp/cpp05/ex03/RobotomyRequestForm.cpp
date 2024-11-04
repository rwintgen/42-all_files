/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:32:21 by romain            #+#    #+#             */
/*   Updated: 2024/10/30 16:55:51 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) \
: AForm("RRF", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm " << AForm::getName() << " created"  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) \
: AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm " << AForm::getName() << " destroyed"  << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << "*wrrzzzzzz, wrzz-wrrrrzzzzz*, " << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << this->_target << " couldn't get robotomized" << std::endl;
}

AForm	*RobotomyRequestForm::create(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}
