/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:30:48 by romain            #+#    #+#             */
/*   Updated: 2024/08/12 14:02:34 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	jackie;
	ClapTrap	maya("Maya");
	ScavTrap	krieg;
	ScavTrap	zero("Zero");

	std::cout << std::endl;
	jackie.attack("Maya");
	maya.takeDamage(0);
	maya.beRepaired(5);

	std::cout << std::endl;
	zero.attack("Jackie");
	jackie.takeDamage(20);
	jackie.beRepaired(10);

	std::cout << std::endl;
	krieg.guardGate();
	zero.attack("the gate");
	krieg.takeDamage(20);
	krieg.guardGate();

	std::cout << std::endl;

	return (0);
}
