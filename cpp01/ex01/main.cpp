/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:29:08 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/18 13:53:13 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int i = 5;
	Zombie *horde = zombieHorde(i, "Lasagna");

	for (int j = 0; j < i; j++)
		horde[j].announce();
	delete [] horde;
	return (0);
}
