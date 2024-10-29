/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:37:43 by romain            #+#    #+#             */
/*   Updated: 2024/10/29 16:15:02 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	public:
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal(void);

		AAnimal &operator=(const AAnimal &copy);

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const = 0;

	protected:
		AAnimal(void);
		AAnimal(std::string type);

		std::string _type;
};

#endif