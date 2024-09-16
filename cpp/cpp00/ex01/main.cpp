/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:33 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/16 13:32:25 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>

void	addContactFromTerminal(PhoneBook* phonebook)
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
	std::string	input;

	phonebook->displayAll(void);
	while (!std::cin.eof())
	{
		std::cout << "Enter index of the contact you want to display: ";
		std::getline(std::cin, input);
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
		{
			phonebook->displayOne(input[0] - '0');
			break ;
		}
		else
			std::cout << std::endl << "Please enter a valid index" << std::endl;
	}
}

int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	std::cout << "PhoneBook opened" << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "Please enter ADD, SEARCH or EXIT: ";
		std::getline(std::cin, input);
		if (input == "ADD")
			addContactFromTerminal(&phonebook);
		else if (input == "SEARCH")
			searchContact(&phonebook);
		else if (input == "EXIT" || std::cin.eof())
			break ;
	}
	std::cout << "PhoneBook closed" << std::endl;
	return (0);
}
