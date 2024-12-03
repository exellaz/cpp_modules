/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:48:22 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 16:04:48 by kkhai-ki         ###   ########.fr       */
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
	Ice				*ice = new Ice();
	Cure			*cure = new Cure();
	Ice				*none = NULL;
	Character		Player1("Guy");
	Character		Player2("Chicken");
	MateriaSource	Source;

	Player1.equip(ice);
	Player1.equip(none);
	Player1.unequip(1);
	Player1.use(0, Player2);
	Player1.unequip(0);
	Player1.use(0, Player2);
	// Player1.equip(ice);
	// Player1.use(0, Player2);
	Player2.equip(cure);
	Player2.use(0, Player1);
	Source.learnMateria(ice);

	//WIP: add more test cases
}