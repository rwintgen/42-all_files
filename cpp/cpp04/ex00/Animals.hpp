/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:37:43 by romain            #+#    #+#             */
/*   Updated: 2024/08/13 12:32:33 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
# define ANIMALS_HPP

# include <iostream>
# include <string>

class	Animal
{
	public:
		Animal(void);
		Animal(std::string type);
		~Animal(void);

		std::string	getType(void) const;
		void		setType(std::string type);

		virtual void	makeSound(void) const;
	protected:
		std::string	_type;
};

#endif