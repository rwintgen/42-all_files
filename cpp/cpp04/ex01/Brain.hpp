/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:04:48 by romain            #+#    #+#             */
/*   Updated: 2024/10/29 16:14:55 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class	Brain
{
	public:
		Brain(void);
		Brain(const Brain &copy);
		~Brain(void);

		Brain	&operator=(Brain copy);

		std::string	getIdea(unsigned int index) const;
		void		setIdea(unsigned int index, std::string idea);

	private:
		std::string	*_ideas;
};

#endif