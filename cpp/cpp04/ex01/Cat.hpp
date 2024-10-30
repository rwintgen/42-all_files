/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:06:21 by romain            #+#    #+#             */
/*   Updated: 2024/10/30 15:14:13 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &copy);
		~Cat(void);

		Cat		&operator=(const Cat &copy);
	
		void	makeSound(void) const;
		void	addIdea(std::string newIdea);
		void	printAllIdeas(void) const;

	private:
		Brain	*_brain;
};

#endif