/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:17:32 by romain            #+#    #+#             */
/*   Updated: 2024/09/18 14:40:45 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "Giving away food is nice, but it costs the CROUS money..." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "It is so surprising to see that the CROUS machine gives extra food for free!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "The CROUS should really fix their machine, all the students eat for free." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "The CROUS finally fixed their machine. The students are gonna pay for it!!!" << std::endl;
}

void	Harl::complain(const std::string &complaint)
{
	void		(Harl::*fooPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == complaint)
		{
			(this->*fooPtr[i])();
			return ;
		}
	}
	std::cerr << "Harl is a bit lost with this instruction : \"" << complaint << "\"";
}
