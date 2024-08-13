/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:07:19 by romain            #+#    #+#             */
/*   Updated: 2024/08/13 12:08:53 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animals.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		~Dog(void);

		virtual void	makeSound(void) const;	
};

#endif