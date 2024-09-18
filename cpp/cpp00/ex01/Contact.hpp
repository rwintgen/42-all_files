/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:38:54 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/18 16:10:58 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	public:
		std::string	getFirstName(void) const;
		void		setFirstName(std::string str);
		std::string	getSurname(void) const;
		void		setSurname(std::string str);
		std::string	getNickname(void) const;
		void		setNickname(std::string str);
		std::string	getPhone(void) const;
		void		setPhone(std::string str);
		std::string	getSecret(void) const;
		void		setSecret(std::string str);
	
	private:
		std::string	_firstname;
		std::string	_surname;
		std::string	_nickname;
		std::string	_phone;
		std::string	_secret;
};

#endif