/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:33 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/08 13:53:40 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <cstdio>

int	main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	while (true)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
			//
		else if (input == "SEARCH")
			//
		else if (input == "EXIT")
			break ;
	}
	std::cout << "PhoneBook closed" << std::endl;
	return (0);
}