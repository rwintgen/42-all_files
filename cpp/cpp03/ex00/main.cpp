/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:30:48 by romain            #+#    #+#             */
/*   Updated: 2024/09/23 11:06:37 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	jack;
	ClapTrap	maya("Maya");

	std::cout << std::endl;
	jack.attack("Maya");
	maya.takeDamage(0);
	maya.beRepaired(5);

	std::cout << std::endl;
	jack.takeDamage(50);
	jack.beRepaired(5);
	jack.attack("Maya");

	std::cout << std::endl;

	return (0);
}
