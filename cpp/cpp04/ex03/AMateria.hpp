/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:06:52 by romain            #+#    #+#             */
/*   Updated: 2024/09/16 11:43:14 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "IMateriaSource.hpp"

class	AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const &type);
		virtual ~AMateria(void);

		AMateria	&operator=(AMateria const &src);

		std::string const	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

	protected:
		std::string	_type;
};

#endif