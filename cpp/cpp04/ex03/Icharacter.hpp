/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Icharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:02:51 by romain            #+#    #+#             */
/*   Updated: 2024/09/13 11:12:31 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

// Character interface with pure virtual methods
class	ICharacter
{
	public:
		virtual ~ICharacter() {}

		virtual std::string const	&getName() const = 0;

		virtual void				equip(AMateria *m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter &target) = 0;
};

#endif