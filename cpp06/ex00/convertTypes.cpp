/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertTypes.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:55:59 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/14 09:19:16 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	convertChar(const std::string& input)
{
	char	c = input[0];

	std::cout << "CHAR\n";
	std::cout << "char: '";
	if (std::isprint(c))
		std::cout << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

bool isScientific(double num)
{
	std::ostringstream stream;
	stream << num;
	std::string str = stream.str();
	return str.find('e') != std::string::npos || str.find('E') != std::string::npos;
}

void	convertInt(const std::string& input)
{
	char	*endptr;
	double	num = std::strtod(input.c_str(), &endptr);
	int		numInt = static_cast<int>(num);;

	std::cout << "INT\n";
	std::cout << "char: ";
	if (numInt < 0 || numInt > 127)
		std::cout << "impossible\n";
	else {
		if (std::isprint(numInt))
			std::cout << "'" << static_cast<char>(numInt) << "'\n";
		else
			std::cout << "Non displayable\n";
	}
	std::cout << "int: " << numInt << "\n";
	std::cout << "float: " << static_cast<float>(numInt) << ".0f\n";
	std::cout << "double: " << static_cast<double>(numInt) << ".0\n";
}

void convertFloat(const std::string& input)
{
	char *endptr;
	float num = std::strtof(input.c_str(), &endptr);

	std::cout << "FLOAT\n";
	std::cout << "char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible\n";
	else if (std::isprint(static_cast<int>(num)))
		std::cout << "'" << static_cast<char>(num) << "'\n";
	else
		std::cout << "Non displayable\n";

	if (num > INT_MIN && num < INT_MAX)
		std::cout << "int: " << static_cast<int>(num) << "\n";
	else
		std::cout << "int: impossible\n";

	std::cout << "float: ";
	if (num == floorf(num))
		std::cout << num << ".0f\n";
	else
		std::cout << num << "f\n";

	std::cout << "double: ";
	if (num == floorf(num))
		std::cout << static_cast<double>(num) << ".0\n";
	else
		std::cout << static_cast<double>(num) << "\n";
}

void	convertDouble(const std::string& input)
{
	char	*endptr;
	double	num = std::strtod(input.c_str(), &endptr);
	float	floatNum = static_cast<float>(num);

	std::cout << "DOUBLE\n";
	std::cout << "char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible\n";
	else {
		if (std::isprint(num))
			std::cout << "'" << static_cast<char>(num) << "'\n";
		else
			std::cout << "Non displayable\n";
	}

	if (num > INT_MIN && num < INT_MAX)
		std::cout << "int: " << static_cast<int>(num) << "\n";
	else
		std::cout << "int: impossible\n";

	std::cout << "float: ";
	if (num > NEG_FLOAT_MAX && num < FLOAT_MAX) {
		if (floatNum == floorf(floatNum))
			std::cout << floatNum << ".0f\n";
		else
			std::cout << floatNum << "f\n";
	}
	else
		std::cout << "impossible\n";

	std::cout << "double: ";
	if (num == floor(num))
		std::cout << num << ".0\n";
	else
		std::cout << num << "\n";
}

void	convertPseudoLiterals(const std::string& input)
{
	std::cout << "PSEUDO LITERAL\n";
	std::cout << "char: impossible\n" << "int: impossible\n";
	if (input == "nan" || input == "nanf")
		std::cout << "float: nanf\n" << "double: nan\n";
	else if (input[0] != '-')
		std::cout << "float: inff\n" << "double: inf\n";
	else
		std::cout << "float: -inff\n" << "double: -inf\n";
}
