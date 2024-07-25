/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:14:32 by romain            #+#    #+#             */
/*   Updated: 2024/07/25 13:38:23 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string&	Weapon::getType(void)
{
	return (this->_type);
}
