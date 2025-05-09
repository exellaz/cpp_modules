/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkTypes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:19:51 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/14 13:59:56 by kkhai-ki         ###   ########.fr       */
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

/**
 * @brief Validates the numeric format of the input based on its characters and endptr.
 *
 * This function performs internal validation after parsing the input with `strtod`.
 * It checks that:
 * - The input only contains valid characters (digits, optional '.', optional 'f').
 * - The `endptr` points to either '\0' or 'f', ensuring no invalid trailing characters.
 * - If 'f' is present, it must follow a digit and be at the end.
 *
 * @param input The trimmed input string being evaluated.
 * @param endptr A pointer to the first invalid character after parsing with `strtod`.
 * @return true if the input format is valid; false otherwise.
 */
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
	if (*endptr == 'f' && (!std::isdigit(*(endptr - 1)) || *(endptr + 1) != '\0'))
		return false;
	return true;
}

/**
 * @brief Determines the scalar type of the input string.
 *
 * This function analyzes the trimmed input string and identifies its scalar type.
 * It checks in the following order:
 * - Pseudo-literals like "nan", "inf", etc.
 * - Character literals (single printable characters).
 * - Numeric formats using `strtod` and helper logic.
 *
 * The result is one of the enumerated `e_type` values:
 * - CHAR
 * - INT
 * - FLOAT
 * - DOUBLE
 * - PSEUDOLITERAL
 * - NONE (if the input doesn't match any known type or fails input validation)
 *
 * @param input The trimmed scalar input string to check.
 * @return The detected type as a value from the `e_type` enum.
 */
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

	if (dot == std::string::npos && f == std::string::npos && isInt(num))
		return INT;
	else if (dot != std::string::npos && f != std::string::npos && isFloat(num))
		return FLOAT;
	else if (dot != std::string::npos && f == std::string::npos && isDouble())
		return DOUBLE;

	return NONE;
}
