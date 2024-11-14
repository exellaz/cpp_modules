/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:52 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/14 18:34:34 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook phonebook;

	system("clear");
	std::cout << "Welcome to PhoneBook" << std::endl;
	wait_for_enter();
	system("clear");
	while (1)
	{
		display_menu();
		std::getline(std::cin, input);
		system("clear");
		if (std::cin.eof())
			break ;
		if (input.empty())
			continue ;
		else if (input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
		{
			// phonebook.display_contact_table();
			phonebook.search_contact();
		}
		else
		{
			std::cout << "Invalid input." << std::endl;
		}
		// std::cout << input << std::endl;
	}
	return (0);
}
