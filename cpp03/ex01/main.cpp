/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:35:46 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/26 12:05:57 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	defaultScav;
	ScavTrap	Scav("Scav");
	ScavTrap	copyScav(Scav);
	ScavTrap	imposterScav("Imposter");
	imposterScav = Scav;

	std::cout << defaultScav.getName() << std::endl;
	std::cout << defaultScav.getHitPoints() << std::endl;
	std::cout << defaultScav.getEnergyPoints() << std::endl;
	std::cout << defaultScav.getAttackDamage() << std::endl << std::endl;

	std::cout << Scav.getName() << std::endl;
	std::cout << Scav.getHitPoints() << std::endl;
	std::cout << Scav.getEnergyPoints() << std::endl;
	std::cout << Scav.getAttackDamage() << std::endl << std::endl;

	std::cout << copyScav.getName() << std::endl;
	std::cout << copyScav.getHitPoints() << std::endl;
	std::cout << copyScav.getEnergyPoints() << std::endl;
	std::cout << copyScav.getAttackDamage() << std::endl << std::endl;

	std::cout << imposterScav.getName() << std::endl;
	std::cout << imposterScav.getHitPoints() << std::endl;
	std::cout << imposterScav.getEnergyPoints() << std::endl;
	std::cout << imposterScav.getAttackDamage() << std::endl << std::endl;

	defaultScav.attack("Scav");
	imposterScav.takeDamage(20);
	imposterScav.beRepaired(1);
	copyScav.takeDamage(1);
	std::cout << copyScav.getHitPoints() << std::endl;
	std::cout << copyScav.getEnergyPoints() << std::endl;
	copyScav.beRepaired(1);
	std::cout << copyScav.getHitPoints() << std::endl;
	std::cout << copyScav.getEnergyPoints() << std::endl;
	copyScav.guardGate();
}
