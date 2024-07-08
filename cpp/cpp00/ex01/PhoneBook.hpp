/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:52 by rwintgen          #+#    #+#             */
/*   Updated: 2024/07/08 13:02:11 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	public:
		void	AddContact(std::string FirstName, std::string LastName, \
							std::string Nickname, std::string Phone, \
							std::string Secret);
		void	DisplayAll();
		void	DisplayOne(int index);
	
	private:
		int		index;
		Contact	PhoneBook[8];

};

#endif