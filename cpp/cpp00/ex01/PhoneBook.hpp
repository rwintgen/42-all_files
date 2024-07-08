/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:52 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/08 16:16:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		void	addContact(const std::string& firstname, const std::string& surname, \
							const std::string& nickname, const std::string& phone, \
							const std::string& secret);
		void	displayAll();
		void	displayOne(int index);
	
	private:
		inline void	createPhoneBook(void) { this->currentIndex = 0; };
		int			currentIndex;
		Contact		contacts[8];

};

#endif