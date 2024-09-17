/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:03:57 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/17 11:43:14 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName(void) const
{
	return (this->_firstname);
}

void Contact::setFirstName(std::string str)
{
	this->_firstname = str;
}

std::string Contact::getSurname(void) const
{
	return (this->_surname);
}

void Contact::setSurname(std::string str)
{
	this->_surname = str;
}

std::string Contact::getNickname(void) const
{
	return (this->_nickname);
}

void Contact::setNickname(std::string str)
{
	this->_nickname = str;
}

std::string Contact::getPhone(void) const
{
	return (this->_phone);
}

void Contact::setPhone(std::string str)
{
	this->_phone = str;
}

std::string Contact::getSecret(void) const
{
	return (this->_secret);
}

void Contact::setSecret(std::string str)
{
	this->_secret = str;
}
