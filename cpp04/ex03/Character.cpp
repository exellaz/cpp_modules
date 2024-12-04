/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:50:16 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/04 15:08:38 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name)
	: _name(name)
{
	for (int i = 0; i < _inventorySize; i++)
		this->_inventory[i] = NULL;
}

Character::~Character(void)
{
	for (int i = 0; i < _inventorySize; i++)
	{
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
	}
}

Character::Character(Character &src)
{
	*this = src;
}

Character	&Character::operator=(Character &src)
{
	AMateria	**srcInventory = src.getInventory();

	if (this != &src)
	{
		this->_name = src.getName();
		for (int i = 0; i < _inventorySize; i++)
		{
			if (this->_inventory[i] != NULL)
			{
				delete (this->_inventory[i]);
				this->_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < _inventorySize; i++)
		{
			if (srcInventory[i])
				this->_inventory[i] = srcInventory[i]->clone();
		}
	}
	return (*this);
}

const std::string	&Character::getName(void) const
{
	return (this->_name);
}

AMateria	**Character::getInventory(void)
{
	return (this->_inventory);
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << this->_name <<  ": Materia does not exist!" << std::endl;
		return ;
	}
	for (int i = 0; i < _inventorySize; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << this->_name << ": " << m->getType() << " materia equipped at slot " << i << std::endl;
			return ;
		}
	}
	std::cout << this->_name << ": Materia slots full!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->_inventorySize)
	{
		std::cout << this->_name << ": Invalid inventory slot!" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << ": Nothing at slot " << idx << " to unequip" << std::endl;
		return ;
	}
	std::cout << this->_name << ": Unequipped " << this->_inventory[idx]->getType()
	<< " materia from slot " << idx << std::endl;
	this->_inventory[idx] = NULL;
	return ;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->_inventorySize)
	{
		std::cout << this->_name << ": Invalid inventory slot!" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << ": Nothing at slot " << idx << " to use" << std::endl;
		return ;
	}
	std::cout << this->_name << ": ";
	this->_inventory[idx]->use(target);
}