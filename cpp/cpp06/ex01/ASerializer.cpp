/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASerializer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:29:45 by romain            #+#    #+#             */
/*   Updated: 2024/11/03 12:06:23 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASerializer.hpp"

ASerializer::ASerializer(void)
{
}

ASerializer::ASerializer(ASerializer const &src)
{
	(void) src;
}

ASerializer::~ASerializer(void)
{
}

uintptr_t ASerializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* ASerializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
