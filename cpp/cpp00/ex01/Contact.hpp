/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:38:54 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/08 13:26:41 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		inline std::string	getFirstName(void) const { return (firstName); }
		inline void			setFirstName(std::string str) { firstName = str; }
		inline std::string	getLastName(void) const { return (lastName); }
		inline void			setLastName(std::string str) { lastName = str; }
		inline std::string	getNickname(void) const { return (nickname); }
		inline void			setNickname(std::string str) { nickname = str; }
		inline std::string	getPhone(void) const { return (phone); }
		inline void			setPhone(std::string str) { phone = str; }
		inline std::string	getSecret(void) const {return (secret); }
		inline void			setSecret(std::string str) { secret = str; }
	
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
};

#endif