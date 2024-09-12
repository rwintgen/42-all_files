/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:49 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/12 11:59:02 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
}

void	PhoneBook::addContact(const std::string& firstname, \
								const std::string& surname, \
								const std::string& nickname, \
								const std::string& phone, \
								const std::string& secret)
{
	if (firstname.empty() || surname.empty() || nickname.empty() \
		|| phone.empty() || secret.empty())
	{
		std::cout << std::endl << "Error: empty field in contact" << std::endl;
		return ;
	}
	if (this->_index == 8)
		this->_index = 0;
	this->_contacts[this->_index].setFirstName(firstname);
	this->_contacts[this->_index].setSurname(surname);
	this->_contacts[this->_index].setNickname(nickname);
	this->_contacts[this->_index].setPhone(phone);
	this->_contacts[this->_index].setSecret(secret);
	this->_index++;
}

void	PhoneBook::displayAll()
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
