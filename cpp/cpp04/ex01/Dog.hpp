/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:07:19 by romain            #+#    #+#             */
/*   Updated: 2024/10/30 15:14:20 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &copy);
		~Dog(void);

		Dog		&operator=(const Dog &copy);

		void	makeSound(void) const;
		void	addIdea(std::string newIdea);
		void	printAllIdeas(void) const;

	private:
		Brain	*_brain;
};

#endif