/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkTypes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:19:51 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/10 17:40:50 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	isChar(const std::string& input)
{
	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;
	return false;
}

static bool	isInt(double num)
{
	if (errno == ERANGE || num > INT_MAX || num < INT_MIN)
		return false;

	if (num != std::floor(num))
		return false;

	return true;
}

static bool	isFloat(double num)
{
	if (errno == ERANGE || num > FLOAT_MAX || num < NEG_FLOAT_MAX)
		return false;

	return true;
}

static bool	isDouble(double num)
{
	if (errno == ERANGE || num > DOUBLE_MAX || num < NEG_DOUBLE_MAX)
		return false;

	return true;
}

bool	ScalarConverter::checkTypes(const std::string& input)
{
	char	*endptr;
	double	num = std::strtod(input.c_str(), &endptr);
	size_t	dot = input.find('.');
	size_t	f = input.find('f');

	if (dot && !isdigit(input[dot + 1]))
		return false;
	if (*endptr == 'f')
		endptr++;
	for (; *endptr != '\0'; endptr++) {
		if (!std::isspace(*endptr))
			return false;
	}

	if (isChar(input))
		std::cout << "It's a char!\n";
	else if (dot != std::string::npos && f != std::string::npos && isFloat(num))
		std::cout << "It's a float\n";
	else if (dot != std::string::npos && isDouble(num))
		std::cout << "It's a double\n";
	else if (isInt(num))
		std::cout << "It's an int!\n";
	else
		std::cout << "Impossible\n";

	return true;
}
