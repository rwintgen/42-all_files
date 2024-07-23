/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:34:45 by romain            #+#    #+#             */
/*   Updated: 2024/07/23 21:34:19 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	if (argc != 3 || std::stoi(argv[1]) < 0)
	{
		std::cerr << "Usage: " << argv[0] << " [number of zombies]" << "[zombies name]" << std::endl;
		return (1);
	}
	
	int zombiesNb = std::stoi(argv[1]);
	Zombie	*horde = zombieHorde(zombiesNb, argv[2]);

	for (int i = 0; i < zombiesNb; i++)
		horde[i].announce();

	delete []horde;
	return (0);
}
