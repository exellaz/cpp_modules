/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:40:59 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/24 14:54:15 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
	: _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
}

Fixed::Fixed(const int num)
	: _raw_bits(num << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
	: _raw_bits(roundf(num * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

//Return value here allows for chaining of assignment operation (e.g. a = b = c;)
Fixed	&Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (_raw_bits);
}

void	Fixed::setRawBits(const int raw)
{
	_raw_bits = raw;
}

float	Fixed::toInt(void) const
{
	return (_raw_bits >> _bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_raw_bits / (float)(1 << _bits));
}

std::ostream	&operator << (std::ostream &stream, const Fixed &f)
{
	stream << f.toFloat();
	return (stream);
}
