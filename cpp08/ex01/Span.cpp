/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:57:50 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/23 14:47:00 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
	: _maxSize(0)
{
}

Span::Span(unsigned int N)
	: _maxSize(N)
{
}

Span::Span(const Span& src)
	: _numbers(src._numbers),
	_maxSize(src._maxSize)
{
}

Span::~Span()
{
}

Span&	Span::operator=(const Span& src)
{
	if (this != &src) {
		this->_numbers = src._numbers;
		this->_maxSize = src._maxSize;
	}
	return *this;
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::out_of_range("Error: Max size exceeded");

	_numbers.push_back(number);
}

std::vector<int>	Span::getNumbers()
{
	return _numbers;
}

unsigned int	Span::getMaxSize()
{
	return _maxSize;
}
