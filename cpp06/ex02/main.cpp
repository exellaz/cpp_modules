/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:42:42 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/14 18:16:57 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base*	generate(void)
{
	static bool	seeded = 0;
	if (!seeded) {
		std::srand(std::time(0));
		seeded = 1;
	}

	int	i = rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void	identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	} catch (const std::exception &e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	} catch (const std::exception &e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
	} catch (const std::exception &e) {}
}

int	main()
{
	Base*	ptr = generate();
	identify(ptr);
	identify(&(*ptr));
	return 0;
}
