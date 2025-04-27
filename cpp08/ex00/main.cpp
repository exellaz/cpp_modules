/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:36:57 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/24 14:29:57 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>
#include <ctime>

void	run_tests();

int	main()
{
	run_tests();
	return 0;
}

void	test_easyfind_Vector()
{
	std::vector<int>	v;

	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	test_easyfind(v, 7, "easyfind Vector");
}

void	test_easyfind_Deque()
{
	std::deque<int>	d;

	srand(std::time(0));
	for (int i = 0; i < 10; ++i)
		d.push_back(rand() % 10);

	test_easyfind(d, rand() % 10, "easyfind Deque");
}

void	test_easyfind_List()
{
	std::list<int>	l;

	srand(std::time(0));
	for (int i = 0; i < 10; ++i)
		l.push_back(rand() % 10);

	test_easyfind(l, rand() % 10, "easyfind List");
}

void	test_easyfind_Vector_NotFound()
{
	std::vector<int> v;

	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	v.pop_back();
	test_easyfind(v, 9, "easyfind Number Not Found");
}

void	run_tests()
{
	void	(*tests[])() = \
	{
		test_easyfind_Vector,
		test_easyfind_Deque,
		test_easyfind_List,
		test_easyfind_Vector_NotFound,
	};

	int	numTests = sizeof(tests) / sizeof(tests[0]);

	std::cout << "Running " << numTests << " tests...\n\n";
	for (int i = 0; i < numTests; i++)
	{
		tests[i]();
		std::cout << BLUE << "-------------------------------------------" << RESET << std::endl;
	}
}
