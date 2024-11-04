/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:14:22 by romain            #+#    #+#             */
/*   Updated: 2024/11/03 12:08:10 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASerializer.hpp"

int main(void)
{
	Data		data;
	uintptr_t	rawValue;
	Data		*deserializedValue;
	
	data.content = 42;

	std::cout << "Ptr value: " << &data << std::endl;
	
	rawValue = ASerializer::serialize(&data);
	std::cout << "Serialized value: " << rawValue << std::endl;
	std::cout << "Serialized value content: " << data.content << std::endl;
	
	deserializedValue = ASerializer::deserialize(rawValue);
	std::cout << "Deserialized value: " << deserializedValue << std::endl;
	std::cout << "Deserialized value content: " << deserializedValue->content << std::endl;

	return (0);
}
