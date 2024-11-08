/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:52 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/07 19:33:16 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>

class Contact {
	private:
		std::string	fname?
};

int	main(void)
{
	std::string	input;

	while (1)
	{
		std::getline(std::cin, input);
		if (input.empty())
			break ;
		std::cout << input << std::endl;
	}
	return (0);
}
