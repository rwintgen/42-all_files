/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:33 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/21 08:54:15 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>

void	addContact(PhoneBook* phonebook)
{
	std::string fields[5];

	std::cout << "Enter first name: ";
	std::getline(std::cin, fields[0]);
	std::cout << "Enter surname: ";
	std::getline(std::cin, fields[1]);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, fields[2]);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, fields[3]);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, fields[4]);
	phonebook->addContact(fields[0], fields[1], fields[2], fields[3], fields[4]);
}

void	searchContact(PhoneBook* phonebook)
{
	
}

int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	while (true)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
			addContact(&phonebook);
		else if (input == "SEARCH")
			searchContact(&phonebook);
		else if (input == "EXIT" || std::cin.eof())
			break ;
		else
			std::cout << "Please enter ADD, SEARCH or EXIT " << std::endl;
	}
	std::cout << "PhoneBook closed" << std::endl;
	return (0);
}
