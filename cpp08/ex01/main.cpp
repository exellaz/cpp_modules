/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:56:43 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/23 14:45:05 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	Span	spanA;
	Span	span(5);

	span.addNumber(1);
	span.addNumber(2);
	span.addNumber(3);
	span.addNumber(4);
	span.addNumber(5);
	// span.addNumber(6);

	std::cout << spanA.getMaxSize();

	return 0;
}
