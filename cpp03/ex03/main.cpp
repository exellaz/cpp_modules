/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:35:46 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/26 13:03:30 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	defaultDiamond;
	DiamondTrap	Diamond("Diamond");
	DiamondTrap	copyDiamond(Diamond);
	DiamondTrap	imposterDiamond("Imposter");
	imposterDiamond = Diamond;

	std::cout << defaultDiamond.getName() << std::endl;
	std::cout << defaultDiamond.getHitPoints() << std::endl;
	std::cout << defaultDiamond.getEnergyPoints() << std::endl;
	std::cout << defaultDiamond.getAttackDamage() << std::endl << std::endl;

	std::cout << Diamond.getName() << std::endl;
	std::cout << Diamond.getHitPoints() << std::endl;
	std::cout << Diamond.getEnergyPoints() << std::endl;
	std::cout << Diamond.getAttackDamage() << std::endl << std::endl;

	std::cout << copyDiamond.getName() << std::endl;
	std::cout << copyDiamond.getHitPoints() << std::endl;
	std::cout << copyDiamond.getEnergyPoints() << std::endl;
	std::cout << copyDiamond.getAttackDamage() << std::endl << std::endl;

	std::cout << imposterDiamond.getName() << std::endl;
	std::cout << imposterDiamond.getHitPoints() << std::endl;
	std::cout << imposterDiamond.getEnergyPoints() << std::endl;
	std::cout << imposterDiamond.getAttackDamage() << std::endl << std::endl;

	defaultDiamond.attack("Diamond");
	imposterDiamond.takeDamage(20);
	imposterDiamond.beRepaired(1);
	copyDiamond.takeDamage(1);
	std::cout << copyDiamond.getHitPoints() << std::endl;
	std::cout << copyDiamond.getEnergyPoints() << std::endl;
	copyDiamond.beRepaired(1);
	std::cout << copyDiamond.getHitPoints() << std::endl;
	std::cout << copyDiamond.getEnergyPoints() << std::endl << std::endl;
	defaultDiamond.whoAmI();
	Diamond.whoAmI();
	copyDiamond.whoAmI();
	imposterDiamond.whoAmI();
}
