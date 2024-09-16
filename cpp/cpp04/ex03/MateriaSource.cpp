/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwintgen <rwintgen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:33:51 by rwintgen          #+#    #+#             */
/*   Updated: 2024/09/16 14:38:44 by rwintgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; ++i)
        this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
    for (int i = 0; i < 4; ++i)
	{
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; ++i)
        delete this->_inventory[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
    if (this != &src)
	{
        for (int i = 0; i < 4; ++i)
		{
            delete this->_inventory[i];
            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
	{
        if (!this->_inventory[i])
		{
            this->_inventory[i] = m;
            return ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; ++i)
	{
        if (this->_inventory[i] && this->_inventory[i]->getType() == type)
            return (this->_inventory[i]->clone());
    }
    return (NULL);
}
