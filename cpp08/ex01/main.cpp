/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:56:43 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/24 14:38:07 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

template<typename T>
void	printContainer(T& container)
{
	typename T::iterator	lastComma = --container.end();

	std::cout << "{";
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it;
		if (it != lastComma)
			std::cout << ",";
	}
	std::cout << "}\n";
}

int	main()
{
	Span	empty;
	Span	span(5);

	srand(std::time(NULL));
	for (int i = 0; i < 5; ++i)
		span.addNumber(rand() % 20);
	printContainer(span.getNumbers());

	std::cout << empty.getMaxSize() << "\n";
	std::cout << span.longestSpan() << "\n";
	std::cout << span.shortestSpan() << "\n";

	return 0;
}
