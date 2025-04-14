/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkTypes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:19:51 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/14 10:22:22 by kkhai-ki         ###   ########.fr       */
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

static bool	isDouble()
{
	if (errno == ERANGE)
		return false;

	return true;
}

static bool	isPseudoLiteral(const std::string& input)
{
	static const std::string	pseudoLiterals[] = {
		"inf", "+inf", "-inf",
		"inff", "+inff", "-inff",
		"nan", "nanf"
	};

	for (size_t	i = 0; i < sizeof(pseudoLiterals) / sizeof(std::string); i++) {
		if (input == pseudoLiterals[i])
			return true;
	}
	return false;
}

static bool	checkInput(const std::string& input, char *endptr)
{
	if (input.length() == 0)
		return false;
	else if (input.length() > 1) {
		for (size_t i = 0; i < input.length(); i++) {
			if (!std::isdigit(input[i]) && input[i] != 'f' && input[i] != '.')
				return false;
		}
	}
	if (*endptr != 'f' && *endptr != '\0')
		return false;
	if (*endptr == 'f' && !std::isdigit(*(endptr - 1)))
		return false;
	return true;
}

e_type	checkTypes(const std::string& input)
{
	if (isPseudoLiteral(input))
		return PSEUDOLITERAL;
	else if (isChar(input))
		return CHAR;

	char	*endptr;
	double	num = std::strtod(input.c_str(), &endptr);
	size_t	dot = input.find('.');
	size_t	f = input.find('f');

	if (!checkInput(input, endptr))
		return NONE;

	if (f == std::string::npos && isInt(num))
		return INT;
	else if (dot != std::string::npos && f != std::string::npos && isFloat(num))
		return FLOAT;
	else if (dot != std::string::npos && f == std::string::npos && isDouble())
		return DOUBLE;

	return NONE;
}
