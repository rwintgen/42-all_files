/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:49 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/17 11:53:13 by rwintgen         ###   ########.fr       */
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

	std::cout << "Enter first name: ";
	std::getline(std::cin, data[0]);
	std::cout << "Enter surname: ";
	std::getline(std::cin, data[1]);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, data[2]);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, data[3]);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, data[4]);

	if (data[0].empty() || data[1].empty() || data[2].empty() \
		|| data[3].empty() || data[4].empty())
	{
		std::cout << std::endl << "Error: empty field in contact" << std::endl;
		return ;
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

void	PhoneBook::displayAll(void)
{
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|Index     |Name      |Surname   |Nickname  |" << std::endl;
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

		index += std::string(10 - index.length(), ' ');
		name += std::string(10 - name.length(), ' ');
        surname += std::string(10 - surname.length(), ' ');
        nickname += std::string(10 - nickname.length(), ' ');

		std::cout << "|" << index << "|" << name << "|" << surname << "|" << nickname << "|" << std::endl;
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
