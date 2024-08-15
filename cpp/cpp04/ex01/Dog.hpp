/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:07:19 by romain            #+#    #+#             */
/*   Updated: 2024/08/15 17:09:37 by romain           ###   ########.fr       */
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
		virtual ~Dog(void);

		void	swap(Dog &obj1, Dog &obj2);
		Dog		&operator=(const Dog &copy);

		virtual void	makeSound(void) const;
		void			addIdea(std::string newIdea);
		void			printAllIdeas(void) const;
	private:
		Brain	*_brain;
};

#endif