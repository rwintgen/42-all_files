/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:43:54 by romain            #+#    #+#             */
/*   Updated: 2024/08/15 17:07:48 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "Animal.hpp"

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();

		WrongAnimal	&operator=(WrongAnimal other);
		void		swap(WrongAnimal &first, WrongAnimal &second);

		std::string	getType() const;
		void		setType(std::string type);

		void		makeSound() const;
	protected:
		std::string	_type;
};

#endif