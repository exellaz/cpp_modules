/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:43:16 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/09 09:55:24 by kkhai-ki         ###   ########.fr       */
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
	checkTypes(input);
}
