/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:15:20 by romain            #+#    #+#             */
/*   Updated: 2024/09/23 11:37:32 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap &obj);
		FragTrap(std::string name);
		~FragTrap(void);

		FragTrap	&operator=(const FragTrap &obj);

		void	highFivesGuys(void);
		void	attack(std::string const &target);
};

#endif