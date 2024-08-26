/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASerializer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:29:45 by romain            #+#    #+#             */
/*   Updated: 2024/08/26 14:56:49 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASerializer.hpp"

ASerializer::ASerializer()
{
	std::cout << "ASerializer constructor called" << std::endl;
}

ASerializer::ASerializer(ASerializer const &src)
{
	std::cout << "ASerializer copy constructor called" << std::endl;
	*this = src;
}

ASerializer::~ASerializer()
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
