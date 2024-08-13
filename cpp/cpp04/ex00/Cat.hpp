/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:06:21 by romain            #+#    #+#             */
/*   Updated: 2024/08/13 12:31:25 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animals.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		~Cat(void);
	
		virtual void	makeSound(void) const;	
};

#endif