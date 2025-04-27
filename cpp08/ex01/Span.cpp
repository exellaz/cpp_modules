/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:57:50 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/25 13:11:46 by kkhai-ki         ###   ########.fr       */
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
		throw std::out_of_range("Max size exceeded");

	_numbers.push_back(number);
}

int	Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

	return *maxIt - *minIt;
}

int	Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int	minDiff = std::abs(sorted[1] - sorted[0]);
	for (size_t i = 1; i < sorted.size() - 1; ++i) {
		int	diff = std::abs(sorted[i + 1] - sorted[i]);
		if (diff < minDiff)
			minDiff = diff;
	}
	return minDiff;
}

std::vector<int>&	Span::getNumbers()
{
	return _numbers;
}

unsigned int	Span::getMaxSize() const
{
	return _maxSize;
}
