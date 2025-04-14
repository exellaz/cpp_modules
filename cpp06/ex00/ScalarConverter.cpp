/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:43:16 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/14 11:00:37 by kkhai-ki         ###   ########.fr       */
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

/**
 * @brief Calculates the number of significant digits in a numeric string.
 *
 * Determines how many digits should be used for floating-point precision,
 * based on the input string. Trims leading zeros and adjusts for the presence
 * of a decimal point and trailing 'f'. If precision is overestimated from
 * trailing zeros, cout precision will only apply to significant digits.
 *
 * @param input The numeric input string (e.g., "003.1400f").
 * @return The number of significant digits to use for precision (minimum 6).
 */
static size_t	getPrecision(const std::string& input)
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

/**
 * @brief Trims leading and trailing whitespaces from a string
 *
 * This function iterates from the start and end of the string
 * to find the first and last non-whitespace characters.
 *
 * @param input Input string possibly containing leading/trailing whitespaces.
 * @return std::string A new string with leading and trailing whitespaces removed.
 */
static std::string	getTrimmedInput(const std::string &input)
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

/**
 * @brief Converts a scalar string literal to all possible scalar types.
 *
 * This function takes a string representation of a scalar value (char, int, float, or double),
 * trims whitespace, determines its type, sets an appropriate output precision, and prints
 * the scalar in all convertible forms. It supports detecting and converting pseudo-literals
 * like "nan", "inf", etc., and handles conversion errors.
 *
 * @param input The scalar string literal to convert (e.g., "42", "3.14f", "a", "nan").
 *
 * The conversion process includes:
 * - Trimming leading and trailing whitespaces.
 * - Calculating required precision based on the input.
 * - Identifying the scalar type via `checkTypes`.
 * - Calling the corresponding conversion function.
 *
 * If the input doesn't match any known scalar type, an error message is printed.
 */
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
