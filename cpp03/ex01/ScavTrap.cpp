/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:57:40 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/25 18:12:31 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	: ClapTrap("ScavBot"),
	_hitPoints(100),
	_energyPoints(50),
	_attackDamage(20)
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}
