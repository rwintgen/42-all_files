/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:43:54 by romain            #+#    #+#             */
/*   Updated: 2024/10/29 16:28:51 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "AAnimal.hpp"

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal(std::string type);
		~WrongAnimal(void);

		WrongAnimal	&operator=(WrongAnimal other);

		std::string	getType(void) const;
		void		setType(std::string type);

		void		makeSound(void) const;

	protected:
		std::string	_type;
};

#endif