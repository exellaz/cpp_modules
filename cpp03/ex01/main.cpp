/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:35:46 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/25 14:31:19 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	defaultClap;
	ClapTrap	Clap("Clap");
	ClapTrap	copyClap(Clap);
	ClapTrap	imposterClap("Imposter");
	imposterClap = Clap;

	std::cout << defaultClap.getName() << std::endl;
	std::cout << defaultClap.getHitPoints() << std::endl;
	std::cout << defaultClap.getEnergyPoints() << std::endl;
	std::cout << defaultClap.getAttackDamage() << std::endl << std::endl;

	std::cout << Clap.getName() << std::endl;
	std::cout << Clap.getHitPoints() << std::endl;
	std::cout << Clap.getEnergyPoints() << std::endl;
	std::cout << Clap.getAttackDamage() << std::endl << std::endl;

	std::cout << copyClap.getName() << std::endl;
	std::cout << copyClap.getHitPoints() << std::endl;
	std::cout << copyClap.getEnergyPoints() << std::endl;
	std::cout << copyClap.getAttackDamage() << std::endl << std::endl;

	std::cout << imposterClap.getName() << std::endl;
	std::cout << imposterClap.getHitPoints() << std::endl;
	std::cout << imposterClap.getEnergyPoints() << std::endl;
	std::cout << imposterClap.getAttackDamage() << std::endl << std::endl;

	defaultClap.attack("Clap");
	imposterClap.takeDamage(10);
	imposterClap.beRepaired(1);
	copyClap.takeDamage(1);
	std::cout << copyClap.getHitPoints() << std::endl;
	std::cout << copyClap.getEnergyPoints() << std::endl;
	copyClap.beRepaired(1);
	std::cout << copyClap.getHitPoints() << std::endl;
	std::cout << copyClap.getEnergyPoints() << std::endl;
}
