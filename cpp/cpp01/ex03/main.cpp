/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:35:31 by romain            #+#    #+#             */
/*   Updated: 2024/09/12 12:11:52 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		Weapon  club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack(void);
		club.setType("some other type of club");
		bob.attack(void);
	}
	{
		Weapon  club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack(void);
		club.setType("some other type of club");
		jim.attack(void);
	}
}
