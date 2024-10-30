/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:58:40 by romain            #+#    #+#             */
/*   Updated: 2024/10/30 12:54:37 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Krieg") , _keeperMode(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ClapTrap " << this->_name << " just became a ScavTrap!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	*this = obj;
	std::cout << "Copy constructor of ScavTrap called!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) , _keeperMode(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ClapTrap " << this->_name << " just became a ScavTrap!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destroyed!" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	if (this != &obj)
	{
		ClapTrap::operator=(obj);
		this->_keeperMode = obj._keeperMode;
		std::cout << "Assignment operator of ScavTrap called!" << std::endl;
	}
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
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

void	ScavTrap::attack(std::string const &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << _name << " deals a strong blow to " << target \
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;	
	}
	else
		std::cout << _name << " can't attack right now." << std::endl;
}
