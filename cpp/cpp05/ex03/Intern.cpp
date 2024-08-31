/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:17:51 by romain            #+#    #+#             */
/*   Updated: 2024/08/21 13:16:54 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(Intern const &src)
{
	*this = src;
	std::cout << "Intern created from copy constructor" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

Intern	&Intern::operator=(Intern const &src)
{
	(void)src;
	return (*this);
}

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	if (name.empty() || target.empty())
		throw AForm::EmptyNameException();

	std::string	const formNames[3] = {"ShrubberyCreationForm",
										"RobotomyRequestForm",
										"PresidentialPardonForm"};
	AForm *(*formCreators[3])(std::string const &) = {ShrubberyCreationForm::create,
														RobotomyRequestForm::create,
														PresidentialPardonForm::create};
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
			return (formCreators[i](target));
	}
	throw AForm::InvalidFormException();	
}