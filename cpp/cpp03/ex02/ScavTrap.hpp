/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:58:43 by romain            #+#    #+#             */
/*   Updated: 2024/09/23 11:37:33 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap &obj);
		ScavTrap(std::string name);
		~ScavTrap(void);

		ScavTrap	&operator=(const ScavTrap &obj);

		void	guardGate(void);
		void	attack(std::string const &target);

	private:
		bool	_keeperMode;
};

#endif