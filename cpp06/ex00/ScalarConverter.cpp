/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:43:16 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/14 10:20:54 by kkhai-ki         ###   ########.fr       */
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

ScalarConverter::~ScalarConverter()
{
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
	if (precision < 6)
		precision = 6;
	return precision;
}

std::string	getTrimmedInput(const std::string &input)
{
	if (input.length() == 1)
		return input;

	size_t start = 0;
	while (start < input.length() && std::isspace(input[start]))
		start++;

	size_t end = input.length();
	while (end > start && std::isspace(input[end - 1]))
		end--;

	return input.substr(start, end - start);
}

void	ScalarConverter::convert(const std::string& input)
{
	std::string	trimmedInput = getTrimmedInput(input);
	size_t		precision = getPrecision(trimmedInput);
	std::cout << std::setprecision(precision);

	e_type	type = checkTypes(trimmedInput);
	switch (type) {
		case CHAR:
			convertChar(trimmedInput);
			break;
		case INT:
			convertInt(trimmedInput);
			break;
		case FLOAT:
			convertFloat(trimmedInput);
			break;
		case DOUBLE:
			convertDouble(trimmedInput);
			break;
		case PSEUDOLITERAL:
			convertPseudoLiterals(trimmedInput);
			break;
		default:
			errNoConversion();
	}
}
