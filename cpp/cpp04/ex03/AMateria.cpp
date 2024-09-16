/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:31:14 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/16 14:23:21 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default")
{
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::~AMateria(void)
{
}

AMateria	&AMateria::operator=(AMateria const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	// TODO implement use function
	std::cout << "Using AMateria on " << target.getName() << std::endl;
}
