/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:52 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/08 15:51:56 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int	main(void)
{
	std::string	input;

	while (1)
	{
		std::getline(std::cin, input);
		if (input.empty() || input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			//Do ADD
		}
		else if (input == "SEARCH")
		{
			//Do SEARCH
		}
		else
		{
			std::cout << "Invalid input. Please choose ADD, SEARCH or EXIT" << std::endl;
		}
		// std::cout << input << std::endl;
	}
	return (0);
}
