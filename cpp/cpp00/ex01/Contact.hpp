/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:38:54 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/19 20:41:29 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		inline std::string	getFirstName(void) const { return (firstname); }
		inline void			setFirstName(std::string str) { firstname = str; }
		inline std::string	getSurname(void) const { return (surname); }
		inline void			setSurname(std::string str) { surname = str; }
		inline std::string	getNickname(void) const { return (nickname); }
		inline void			setNickname(std::string str) { nickname = str; }
		inline std::string	getPhone(void) const { return (phone); }
		inline void			setPhone(std::string str) { phone = str; }
		inline std::string	getSecret(void) const {return (secret); }
		inline void			setSecret(std::string str) { secret = str; }
	
	private:
		std::string	firstname;
		std::string	surname;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
};

#endif