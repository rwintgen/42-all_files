/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:12:46 by romain            #+#    #+#             */
/*   Updated: 2024/09/16 11:44:30 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

class	Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		virtual ~Character(void);

		Character	&operator=(Character const &src);

		std::string const	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

	private:
		std::string	_name;
		AMateria	*_inventory[4];
};

#endif