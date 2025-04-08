/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:43:16 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/08 16:02:14 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter& src)
{
	*this = src;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter& src)
{
	(void)src;
	return *this;
}

void	ScalarConverter::convert(const std::string& input)
{
	if (input.length() == 1 && (input[0] < '0' || input[0] > '9'))
		std::cout << "It's a char!\n";
}
