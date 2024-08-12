/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:30:59 by romain            #+#    #+#             */
/*   Updated: 2024/08/12 14:03:09 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Jackie"), _healthPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _healthPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap "<< _name << " destroyed!" << std::endl;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_energyPoints > 0 && this->_healthPoints > 0)
	{
		std::cout << _name << " attacks " << target \
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;	
	}
	else
		std::cout << _name << " can't attack right now." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_healthPoints > 0)
	{
		std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
		this->_healthPoints -= amount;
		if (this->_healthPoints <= 0)
			std::cout << _name << " is dead..." << std::endl;
	}
	else
		std::cout << _name << " is already dead..." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_healthPoints > 0)
	{
		std::cout << _name << " gets repaired for " << amount << " points." << std::endl;
		this->_healthPoints += amount;
		this->_energyPoints--;
		if (this->_healthPoints > 10)
		{
			this->_healthPoints = 10;
			std::cout << _name << " is at full life!" << std::endl;
		}
	}
	else
		std::cout << _name << " can't repair itself right now..." << std::endl;
}
