/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:15:20 by romain            #+#    #+#             */
/*   Updated: 2024/08/15 17:31:31 by romain           ###   ########.fr       */
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