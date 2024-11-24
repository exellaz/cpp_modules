/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:18:41 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/24 21:14:59 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float getArea(Point const a, Point const b, Point const c)
{
	float result;

	result = ((c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) +
			(a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
			(b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))) / 2;
	if (result < 0)
		return (-1 * result);
	return (result);
}

bool	bsp(Point const a, Point const b, Point const c,  Point const point)
{
	float	triangleArea = getArea(a, b, c);
	float	areaPAB = getArea(point, a, b);
	float	areaPBC = getArea(point, b, c);
	float	areaPCA = getArea(point, c, a);
	float	totalAreaP = areaPAB + areaPBC + areaPCA;

	if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
		return (false);
	if (totalAreaP == triangleArea)
		return (true);
	return (false);
}
