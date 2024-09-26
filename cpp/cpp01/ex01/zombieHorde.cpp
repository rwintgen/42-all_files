/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:34:24 by romain            #+#    #+#             */
/*   Updated: 2024/09/26 15:00:03 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];

	if (name.empty())
		name = "default";

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
