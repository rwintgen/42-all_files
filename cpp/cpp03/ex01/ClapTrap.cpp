/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:30:59 by romain            #+#    #+#             */
/*   Updated: 2024/08/15 17:35:25 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Jack"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy constructor of ClapTrap called!" << std::endl;
	*this = obj;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap "<< _name << " destroyed!" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Assignment operator of ClapTrap called!" << std::endl;
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
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
	if (this->_hitPoints > 0)
	{
		std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints <= 0)
			std::cout << _name << " is dead..." << std::endl;
	}
	else
		std::cout << _name << " is already dead..." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << _name << " gets repaired for " << amount << " points." << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
		if (this->_hitPoints > 10)
		{
			this->_hitPoints = 10;
			std::cout << _name << " is at full life!" << std::endl;
		}
	}
	else
		std::cout << _name << " can't repair itself right now..." << std::endl;
}
