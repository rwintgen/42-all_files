/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:14:22 by romain            #+#    #+#             */
/*   Updated: 2024/08/26 15:14:25 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASerializer.hpp"

int main()
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
