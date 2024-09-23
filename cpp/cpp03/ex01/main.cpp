/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:30:48 by romain            #+#    #+#             */
/*   Updated: 2024/09/23 11:37:35 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	jack;
	ClapTrap	maya("Maya");
	ScavTrap	krieg;
	ScavTrap	zero("Zero");

	std::cout << std::endl;
	jack.attack("Maya");
	maya.takeDamage(0);
	maya.beRepaired(5);

	std::cout << std::endl;
	zero.attack("Jack");
	jack.takeDamage(20);
	jack.beRepaired(5);

	std::cout << std::endl;
	krieg.guardGate();
	zero.attack("the gate");
	krieg.takeDamage(20);
	krieg.guardGate();
	krieg.beRepaired(10);

	std::cout << std::endl;

	return (0);
}
