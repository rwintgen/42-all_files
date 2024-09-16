/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:03:57 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/16 11:13:06 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName(void) const
{
	return (this->firstName);
}

void Contact::setFirstName(std::string str)
{
	this->firstName = str;
}

std::string Contact::getSurname(void) const
{
	return (this->surname);
}

void Contact::setSurname(std::string str)
{
	this->surname = str;
}

std::string Contact::getNickname(void) const
{
	return (this->nickname);
}

void Contact::setNickname(std::string str)
{
	this->nickname = str;
}

std::string Contact::getPhone(void) const
{
	return (this->phone);
}

void Contact::setPhone(std::string str)
{
	this->phone = str;
}

std::string Contact::getSecret(void) const
{
	return (this->secret);
}

void Contact::setSecret(std::string str)
{
	this->secret = str;
}
