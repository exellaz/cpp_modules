/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:33:48 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/14 10:55:20 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char *av[])
{
	if (ac != 2) {
		std::cerr << "Invalid number of arguments.\n Usage: ./convert [string]\n";
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
