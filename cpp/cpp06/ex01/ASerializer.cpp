/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASerializer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:29:45 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:29:26 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASerializer.hpp"

ASerializer::ASerializer(void)
{
	std::cout << "ASerializer constructor called" << std::endl;
}

ASerializer::ASerializer(ASerializer const &src)
{
	std::cout << "ASerializer copy constructor called" << std::endl;
	*this = src;
}

ASerializer::~ASerializer(void)
{
	std::cout << "ASerializer destructor called" << std::endl;
}

uintptr_t ASerializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* ASerializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
