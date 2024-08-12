/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:30:48 by romain            #+#    #+#             */
/*   Updated: 2024/08/12 14:02:28 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	jackie;
	ClapTrap	maya("Maya");

	std::cout << std::endl;
	jackie.attack("Maya");
	maya.takeDamage(0);
	maya.beRepaired(5);

	std::cout << std::endl;
	jackie.takeDamage(50);
	jackie.beRepaired(5);

	std::cout << std::endl;

	return (0);
}
