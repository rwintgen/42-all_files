/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:52 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/08 13:30:34 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	public:
		void	addContact(const std::string& FirstName, const std::string& LastName, \
							const std::string& Nickname, const std::string& Phone, \
							const std::string& Secret);
		void	displayAll();
		void	displayOne(int index);
	
	private:
		int		currentIndex;
		Contact	contacts[8];

};

#endif