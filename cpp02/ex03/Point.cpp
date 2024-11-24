/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:03:27 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/24 17:48:59 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
	: _x(Fixed(0)),
	_y(Fixed(0))
{

}

Point::~Point(void)
{

}

Point::Point(const float x, const float y)
	: _x(Fixed(x)),
	_y(Fixed(y))
{

}

Point::Point(Fixed x, Fixed y)
	: _x(x),
	_y(y)
{

}

Point::Point(const Point &other)
	: _x(other.getX()),
	_y(other.getY())
{

}

Point	&Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}
