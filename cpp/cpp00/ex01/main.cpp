/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:33 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/17 11:52:12 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>

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
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT" || std::cin.eof())
			break ;
	}
	std::cout << "PhoneBook closed" << std::endl;
	return (0);
}
