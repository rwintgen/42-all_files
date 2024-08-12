/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:30:48 by romain            #+#    #+#             */
/*   Updated: 2024/08/12 13:58:00 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	jackie;
	ClapTrap	maya("Maya");
	ScavTrap	krieg;
	ScavTrap	zero("Zero");

	jackie.attack("Maya");
	maya.takeDamage(0);
	maya.beRepaired(5);

	zero.scavAttack("Jackie");
	jackie.takeDamage(20);
	jackie.beRepaired(10);

	krieg.guardGate();
	zero.scavAttack("the gate");
	krieg.takeDamage(20);
	krieg.guardGate();

	return (0);
}
