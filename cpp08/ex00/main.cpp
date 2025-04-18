/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:36:57 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/18 23:19:01 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

void	run_tests();

int	main()
{
	// std::vector<int>	v;

	// for (int i = 0; i < 10; ++i)
	// 	v.push_back(i);

	// for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	// 	std::cout << *it << "\n";

	// std::vector<int>::iterator needle;

	// try {
	// 	needle = easyfind(v, 12);
	// 	std::cout << *needle << "\n";
	// }
	// catch (std::exception &e) {
	// 	std::cout << e.what() << "\n";
	// }
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

	for (int i = 0; i < 100; ++i)
		d.push_back(i);

	test_easyfind(d, 53, "easyfind Deque");
}

void	test_easyfind_List()
{
	std::list<int>	l;

	for (int i = 0; i < 1000; ++i)
		l.push_back(i);

	test_easyfind(l, 289, "easyfind List");
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
