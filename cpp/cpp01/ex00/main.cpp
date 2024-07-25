/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:13:05 by romain            #+#    #+#             */
/*   Updated: 2024/07/25 13:16:33 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie1 = newZombie("Zombiz");
	Zombie	*zombie2 = newZombie("Zomboz");
	
	randomChump("Zombib");
	randomChump("Zombob");

	zombie1->announce();
	delete (zombie1);

	zombie2->announce();
	delete (zombie2);

	return (EXIT_SUCCESS);
}
