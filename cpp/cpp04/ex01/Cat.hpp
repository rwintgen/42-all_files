/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:06:21 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 13:16:10 by rwintgen         ###   ########.fr       */
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
		virtual ~Cat(void);

		void	swap(Cat &obj1, Cat &obj2);
		Cat		&operator=(const Cat &copy);
	
		virtual void	makeSound(void) const;
		void			addIdea(std::string newIdea);
		void			printAllIdeas(void) const;

	private:
		Brain	*_brain;
};

#endif