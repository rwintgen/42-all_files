/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:04:48 by romain            #+#    #+#             */
/*   Updated: 2024/08/13 18:20:38 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class	Brain
{
	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();

		void	swap(Brain &obj1, Brain &obj2);
		Brain	&operator=(Brain copy);

		std::string	*getIdeas(void) const;
		void		setIdeas(std::string *ideas);
	private:
		std::string	*_ideas;
};

#endif