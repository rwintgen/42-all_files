/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:07:19 by romain            #+#    #+#             */
/*   Updated: 2024/08/13 17:58:35 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &copy);
		virtual ~Dog(void);

		void	swap(Dog &obj1, Dog &obj2);
		Dog		&operator=(const Dog &copy);

		virtual void	makeSound(void) const;	
};

#endif