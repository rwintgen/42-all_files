/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:49 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/08 17:22:05 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	AddContact(std::string firstname, std::string surname, \
					std::string nickname, std::string phone, std::string secret)
{
	if (firstame.empty() || surname.empty() || nickname.empty() \
		|| phone.empty() || secret.empty())
	{
		std::cout << "Error: empty fields in contact" << std::endl;
		return ;
	}
	if (this->index == 8)
		this->index = 0;
	Contact[this->currentIndex].setFirstName(FirstName);
	Contact[this->currentIndex].setSurname(Surname);
	Contact[this->currentIndex].set
	Contact[this->currentIndex].set
	Contact[this->currentIndex].set
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

void	DisplayAll()
{
	// print first row
	// while i < 8
		// print upper delimiter
		// if (!contact[i].empty)
			// print contact info
	// print lower row
}

void	DisplayOne(int index)
{
	std::cout << "Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Surname: " << contacts[index].getSurname() std::endl;
	std::cout << "AKA: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone: " << contacts[index].getPhone() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getSecret() << std::endl;
}
