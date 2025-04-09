/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkTypes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:19:51 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/09 18:36:03 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	isChar(const std::string& input)
{
	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;
	return false;
}

static bool	isInt(const std::string& input)
{
	char	*ptr;

	errno = 0;
	double	num = std::strtod(input.c_str(), &ptr);
	std::cout << num << "\n";

	if (errno == ERANGE || num > INT_MAX || num < INT_MIN)
		return false;

	std::string	remaining_str(ptr);
	if (!remaining_str.empty())
		return false;

	if (num != std::floor(num))
		return false;

	return true;
}

static bool	isFloat(const std::string& input)
{
	char	*ptr;

	errno = 0;
	double	num = std::strtod(input.c_str(), &ptr);
	std::cout << num << "\n";

	if (errno == ERANGE || num > FLOAT_MAX || num < FLOAT_MIN)
		return false;

	std::string	remaining_str(ptr);
	if (!remaining_str.empty())
		return false;

	// if (num != std::floor(num))
	// 	return false;

	return true;
}

bool	ScalarConverter::checkTypes(const std::string& input)
{
	if (isChar(input))
		std::cout << "It's a char!\n";
	if (isInt(input))
		std::cout << "It's an int!\n";
	if (isFloat(input))
		std::cout << "It's a float\n";

	return true;
}
