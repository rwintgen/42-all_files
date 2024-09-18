/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:13:05 by romain            #+#    #+#             */
/*   Updated: 2024/09/18 14:20:53 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie1 = newZombie("Zombiz");
	Zombie	*zombie2 = newZombie("Zomboz");
	Zombie	*zombie3 = newZombie("");
	
	randomChump("Zombib");
	randomChump("Zombob");
	randomChump("");

	zombie1->announce();
	delete (zombie1);

	zombie2->announce();
	delete (zombie2);

	zombie3->announce();
	delete (zombie3);

	return (0);
}
