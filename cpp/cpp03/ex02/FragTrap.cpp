/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:15:23 by romain            #+#    #+#             */
/*   Updated: 2024/08/15 17:33:56 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Salvador")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "ClapTrap " << this->_name << " just became a FragTrap!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	this->_name = obj._name;
    this->_hitPoints = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
	std::cout << "Copy constructor of FragTrap called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "ClapTrap " << this->_name << " just became a FragTrap!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destroyed!" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	std::cout << "Assignment operator of FragTrap called!" << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " high fives everyone!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "FragTrap " << this->_name << " can't high five right now." << std::endl;
}

void	FragTrap::attack(std::string const &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << _name << " deals a very strong blow to " << target \
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;	
	}
	else
		std::cout << _name << " can't attack right now." << std::endl;
}
