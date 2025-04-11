/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:43:16 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/11 18:12:46 by kkhai-ki         ###   ########.fr       */
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

size_t	getPrecision(const std::string& input)
{
	size_t	index = input.std::string::find_first_not_of('0');
	size_t	precision;

	if (index == std::string::npos)
		precision = 0;
	else
		precision = std::strlen(input.c_str() + index);

	input.std::string::find('.');
	if (input.std::string::find('.') != std::string::npos)
		precision--;
	if (input.std::string::find('f') != std::string::npos)
		precision--;

	return precision;
}

void	ScalarConverter::convert(const std::string& input)
{
	size_t	precision = getPrecision(input);
	// size_t	precision = 800;
	std::cout << std::setprecision(precision);
	e_type	type = checkTypes(input);
	switch (type) {
		case CHAR:
			convertChar(input);
			break;
		case INT:
			convertInt(input);
			break;
		case FLOAT:
			convertFloat(input);
			break;
		case DOUBLE:
			convertDouble(input);
		default:
			break;
	}
}
