/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:48:22 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 15:11:26 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"

int	main(void)
{
	Ice			*ice = new Ice();
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
}