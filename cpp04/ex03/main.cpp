/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:48:22 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/04 17:37:56 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "---Materia test---" << std::endl;
	//Equip, unequip and use existing Materia
	{
		Ice			*ice = new Ice();
		Ice			*ice2 = new Ice();
		Ice			*ice3 = new Ice();
		Cure		*cure = new Cure();
		Cure		*cure2 = new Cure();
		Ice			*none = NULL;
		Character	Player1("Guy");
		Character	Player2("Chicken");

		Player1.equip(ice);
		Player1.equip(none);
		Player1.unequip(1);
		Player1.use(0, Player2);
		Player1.unequip(0);
		Player1.use(0, Player2);
		Player1.equip(ice);
		Player1.use(0, Player2);
		Player2.equip(cure);
		Player2.use(0, Player1);
		Player1.unequip(0);
		Player2.equip(ice);
		Player2.equip(ice2);
		Player2.equip(ice3);
		Player2.equip(cure2);
		Player2.use(3, Player1);
		delete (cure2);
	}
	std::cout << std::endl;
	std::cout << "---MateriaSource test---" << std::endl;
	//MateriaSource tests
	{
		MateriaSource	source;
		Ice				*ice = new Ice();
		Ice				*ice2 = new Ice();
		Ice				*ice3 = new Ice();
		Cure			*cure = new Cure();
		Cure			*cure2 = new Cure();
		AMateria		*newMateria;
		AMateria		*newMateria2;
		Character		Player1("Bob");

		source.learnMateria(ice);
		source.learnMateria(cure);
		source.learnMateria(ice2);
		source.learnMateria(ice3);
		source.learnMateria(cure2);
		newMateria = source.createMateria("ice");
		newMateria2 = source.createMateria("cure");
		Player1.equip(newMateria);
		Player1.equip(newMateria2);
	}
	return (0);
}