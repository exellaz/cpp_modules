/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:52 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/13 20:02:00 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	input;
	PhoneBook phonebook;

	system("clear");
	std::cout << "Welcome to PhoneBook" << std::endl;
	while (1)
	{
		// std::getline(std::cin, input);
		phonebook.get_input("You may choose to ADD, SEARCH or EXIT.", input);
		system("clear");
		if (input.empty() || input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			//Do ADD
			phonebook.add_contact();
			system("clear");
		}
		else if (input == "SEARCH")
		{
			//Do SEARCH
			phonebook.display_contact_table();
			phonebook.search_contact();
			system("clear");
		}
		else
		{
			std::cout << "Invalid input." << std::endl;
		}
		// std::cout << input << std::endl;
	}
	return (0);
}
