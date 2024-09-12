/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:52 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/12 11:57:45 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);

		void	addContact(const std::string& firstname, const std::string& surname, \
							const std::string& nickname, const std::string& phone, \
							const std::string& secret);
		void	displayAll();
		void	displayOne(int index);
	
	private:
		void		createPhoneBook(void);
		int			_index;
		Contact		_contacts[8];
};

#endif