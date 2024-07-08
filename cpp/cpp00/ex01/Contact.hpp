/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:38:54 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/08 13:02:09 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		std::string	GetFirstName(void);
		void		SetFirstName(std::string);
		std::string	GetLastName(void);
		void		SetLastName(std::string);
		std::string	GetNickname(void);
		void		SetNickname(std::string);
		std::string	GetPhone(void);
		void		SetPhone(std::string);
		std::string	GetSecret(void);
		void		SetSecret(std::string);
	
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string	Phone;
		std::string	Secret;
};

#endif