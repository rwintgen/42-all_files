/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:30:48 by romain            #+#    #+#             */
/*   Updated: 2024/09/23 11:11:13 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	jack;
	ClapTrap	maya("Maya");
	ScavTrap	krieg;
	ScavTrap	zero("Zero");
	FragTrap	salvador;
	FragTrap	axton("Axton");

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

	std::cout << std::endl;
	axton.attack("Zero");
	zero.takeDamage(30);
	zero.beRepaired(10);

	std::cout << std::endl;
	salvador.highFivesGuys();
	axton.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
