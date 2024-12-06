/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:57:40 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/06 14:11:10 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FragBot")
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap &src) : ClapTrap(src)
{

}

FragTrap	&FragTrap::operator=(FragTrap &src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " has no energy to attack!" << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name << " is fainted." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " gives you a high five." << std::endl;
}
