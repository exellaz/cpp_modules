/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:33:48 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/11 14:45:49 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char *av[])
{
	// double doubleNum = DOUBLE_MIN;
	if (ac != 2)
		return 1;
	ScalarConverter::convert(av[1]);
	// std::cout << std::setprecision << doubleNum << "\n";
	return 0;
}
