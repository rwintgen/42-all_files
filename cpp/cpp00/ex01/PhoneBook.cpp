/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:49 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/21 08:23:59 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addContact(const std::string& firstname, \
								const std::string& surname, \
								const std::string& nickname, \
								const std::string& phone, \
								const std::string& secret)
{
	if (firstname.empty() || surname.empty() || nickname.empty() \
		|| phone.empty() || secret.empty())
	{
		std::cout << "Error: empty field in contact" << std::endl;
		return ;
	}
	if (this->index == 8)
		this->index = 0;
	contacts[this->index].setFirstName(firstname);
	contacts[this->index].setSurname(surname);
	contacts[this->index].setNickname(nickname);
	contacts[this->index].setPhone(phone);
	contacts[this->index].setSecret(secret);
	this->index++;
}

/*
 ___________________________________________
|Index     |Name      |Surname   |Nickname  |
|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|
|          |          |          |          |
|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|
|          |          |          |          |
|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|
|          |          |          |          |
|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|
|          |          |          |          |
|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|
|          |          |          |          |
|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|
|          |          |          |          |
|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|
|          |          |          |          |
|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|
|          |          |          |          |
 ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾


*/

void	PhoneBook::displayAll()
{
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|Index     |Name      |Surname   |Nickname  |" << std::endl;
	std::cout << "|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::string index = std::to_string(i);
		std::string name = contacts[i].getFirstName();
		std::string surname = contacts[i].getSurname();
		std::string nickname = contacts[i].getNickname();

		name = name.length() > 10 ? name.substr(0, 9) + "." : name;
		surname = surname.length() > 10 ? surname.substr(0, 9) + "." : surname;
		nickname = nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname;

		name += std::string(10 - name.length(), ' ');
        surname += std::string(10 - surname.length(), ' ');
        nickname += std::string(10 - nickname.length(), ' ');
	}
	std::cout << " ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ " << std::endl;
}

void	PhoneBook::displayOne(int index)
{
	std::cout << "Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Surname: " << contacts[index].getSurname() << std::endl;
	std::cout << "AKA: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone: " << contacts[index].getPhone() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getSecret() << std::endl;
}
