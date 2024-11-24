/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:40:00 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/24 21:22:10 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	triA(Fixed(0), Fixed(0));
	Point	triB(Fixed(5), Fixed(0));
	Point	triC(Fixed(0), Fixed(5));

	Point	P0(Fixed(2), Fixed(2));
	Point	P1(Fixed(4.01f), Fixed(0.85f));
	Point	P2(Fixed(3.6f), Fixed(1.39f));
	Point	P3(Fixed(3.67f), Fixed(1.33f));
	Point	P4(Fixed(5), Fixed(0));
	Point	P5(Fixed(200), Fixed(-1.2f));

	std::cout << P1.getY() << std::endl;
	std::cout << "Result (P0): " << bsp(triA, triB, triC, P0) << " Expected: 1" << std::endl;
	std::cout << "Result (P1): " << bsp(triA, triB, triC, P1) << " Expected: 1" << std::endl;
	std::cout << "Result (P2): " << bsp(triA, triB, triC, P2) << " Expected: 1" << std::endl;
	std::cout << "Result (P3): " << bsp(triA, triB, triC, P3) << " Expected: 0" << std::endl;
	std::cout << "Result (P4): " << bsp(triA, triB, triC, P4) << " Expected: 0" << std::endl;
	std::cout << "Result (P5): " << bsp(triA, triB, triC, P5) << " Expected: 0" << std::endl;
	return (0);
}
