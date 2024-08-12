/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:58:40 by romain            #+#    #+#             */
/*   Updated: 2024/08/12 13:42:54 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap (void) : ClapTrap("Krieg") , _keeperMode(false)
{
	this->_healthPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ClapTrap " << this->_name << " just became a ScavTrap!" << std::endl;
}

ScavTrap::ScavTrap (std::string name) : ClapTrap(name) , _keeperMode(false)
{
	this->_healthPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ClapTrap " << this->_name << " just became a ScavTrap!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destroyed!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_healthPoints > 0 && this->_energyPoints > 0)
	{
		if (this->_keeperMode == false)
		{
			this->_keeperMode = true;
			this->_energyPoints--;
			std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
		}
		else
			std::cout << "ScavTrap " << this->_name << " is already guarding the gate." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " can't guard the gate right now." << std::endl;
}
