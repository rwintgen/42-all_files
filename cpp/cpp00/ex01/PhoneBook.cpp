/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:49 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/20 14:41:06 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
}

void	PhoneBook::addContact(void)
{
	std::string	data[5];
	std::string prompts[5] =
	{
		"Enter first name: ",
		"Enter surname: ",
		"Enter nickname: ",
		"Enter phone number: ",
		"Enter darkest secret: "
	};

	for (int i = 0; i < 5; i++)
	{
		std::cout << prompts[i];
		if (!std::getline(std::cin, data[i]) || data[i].empty())
		{
			std::cout << std::endl << "Error: empty field in contact" << std::endl;
			return;
		}
	}
	if (this->_index == 8)
		this->_index = 0;

	this->_contacts[this->_index].setFirstName(data[0]);
	this->_contacts[this->_index].setSurname(data[1]);
	this->_contacts[this->_index].setNickname(data[2]);
	this->_contacts[this->_index].setPhone(data[3]);
	this->_contacts[this->_index].setSecret(data[4]);
	this->_index++;
}

void	PhoneBook::searchContact(void)
{
	std::string	input;

	this->displayAll();
	while (!std::cin.eof())
	{
		std::cout << "Enter index of the contact you want to display: ";
		std::getline(std::cin, input);
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
		{
			this->displayOne(input[0] - '0');
			break ;
		}
		else
			std::cout << "Please enter a valid index" << std::endl;
	}
}

void PhoneBook::displayAll(void)
{
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|" << std::setw(10) << std::right << "Index"
			  << "|" << std::setw(10) << std::right << "Name"
			  << "|" << std::setw(10) << std::right << "Surname"
			  << "|" << std::setw(10) << std::right << "Nickname"
			  << "|" << std::endl;
	std::cout << "|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::string index(1, '0' + i);
		std::string name = this->_contacts[i].getFirstName();
		std::string surname = this->_contacts[i].getSurname();
		std::string nickname = this->_contacts[i].getNickname();

		name = name.length() > 10 ? name.substr(0, 9) + "." : name;
		surname = surname.length() > 10 ? surname.substr(0, 9) + "." : surname;
		nickname = nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname;

		std::cout << "|" << std::setw(10) << std::right << index
				  << "|" << std::setw(10) << std::right << name
				  << "|" << std::setw(10) << std::right << surname
				  << "|" << std::setw(10) << std::right << nickname
				  << "|" << std::endl;
	}
	std::cout << " ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ " << std::endl;
}

void	PhoneBook::displayOne(int index)
{
	std::cout << "Name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Surname: " << this->_contacts[index].getSurname() << std::endl;
	std::cout << "AKA: " << this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone: " << this->_contacts[index].getPhone() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index].getSecret() << std::endl;
}
