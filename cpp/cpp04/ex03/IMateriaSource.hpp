/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:05:40 by romain            #+#    #+#             */
/*   Updated: 2024/09/13 11:07:51 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class	IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}

		virtual void		learnMateria(AMateria *m) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif