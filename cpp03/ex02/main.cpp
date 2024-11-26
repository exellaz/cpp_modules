/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:35:46 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/26 12:28:32 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	defaultFrag;
	FragTrap	Frag("Frag");
	FragTrap	copyFrag(Frag);
	FragTrap	imposterFrag("Imposter");
	imposterFrag = Frag;

	std::cout << defaultFrag.getName() << std::endl;
	std::cout << defaultFrag.getHitPoints() << std::endl;
	std::cout << defaultFrag.getEnergyPoints() << std::endl;
	std::cout << defaultFrag.getAttackDamage() << std::endl << std::endl;

	std::cout << Frag.getName() << std::endl;
	std::cout << Frag.getHitPoints() << std::endl;
	std::cout << Frag.getEnergyPoints() << std::endl;
	std::cout << Frag.getAttackDamage() << std::endl << std::endl;

	std::cout << copyFrag.getName() << std::endl;
	std::cout << copyFrag.getHitPoints() << std::endl;
	std::cout << copyFrag.getEnergyPoints() << std::endl;
	std::cout << copyFrag.getAttackDamage() << std::endl << std::endl;

	std::cout << imposterFrag.getName() << std::endl;
	std::cout << imposterFrag.getHitPoints() << std::endl;
	std::cout << imposterFrag.getEnergyPoints() << std::endl;
	std::cout << imposterFrag.getAttackDamage() << std::endl << std::endl;

	defaultFrag.attack("Frag");
	imposterFrag.takeDamage(20);
	imposterFrag.beRepaired(1);
	copyFrag.takeDamage(1);
	std::cout << copyFrag.getHitPoints() << std::endl;
	std::cout << copyFrag.getEnergyPoints() << std::endl;
	copyFrag.beRepaired(1);
	std::cout << copyFrag.getHitPoints() << std::endl;
	std::cout << copyFrag.getEnergyPoints() << std::endl;
	copyFrag.highFivesGuys();
}
