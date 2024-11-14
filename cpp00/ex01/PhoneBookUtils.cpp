/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:27:42 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/14 16:33:48 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "PhoneBookUtils.hpp"

void	wait_for_enter(void)
{
	std::cout << "Press Enter to continue..." << std::endl;
	while (1)
	{
		if (std::cin.get() == '\n')
			break ;
		else if (std::cin.eof())
		{
			system("clear");
			exit(0);
		}
	}
	system("clear");
}

void	display_menu(void)
{
	std::cout << "+------------MAIN MENU------------+" << std::endl;
	std::cout << "| ADD: to add a new contact       |" << std::endl;
	std::cout << "| SEARCH: to search for a contact |" << std::endl;
	std::cout << "| EXIT: to exit the phonebook     |" << std::endl;
	std::cout << "+---------------------------------+" << std::endl;
	std::cout << "Enter your command (ADD, SEARCH, EXIT): ";
}
