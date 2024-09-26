/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:13:05 by romain            #+#    #+#             */
/*   Updated: 2024/09/26 14:56:55 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	try
	{
		Zombie *zombie1 = newZombie("Zombiz");
		if (!zombie1) throw std::bad_alloc();

		Zombie *zombie2 = newZombie("Zomboz");
		if (!zombie2) throw std::bad_alloc();

		Zombie *zombie3 = newZombie("");
		if (!zombie3) throw std::bad_alloc();

		randomChump("Zombib");
		randomChump("Zombob");
		randomChump("");

		zombie1->announce();
		delete zombie1;

		zombie2->announce();
		delete zombie2;

		zombie3->announce();
		delete zombie3;

	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return 1;
	}

	return (0);
}
