/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:14:43 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/18 22:50:17 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define RESET	"\033[0m"

void test_defaultConstructor() {
	std::cout << YELLOW << "[Test] Default Constructor\n" << RESET;
	Array<int>	arr;
	std::cout << "Size: " << arr.size() << std::endl;
}

void	test_parameterizedConstructor() {
	std::cout << YELLOW << "[Test] Constructor with Size\n" << RESET;
	Array<int>	arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 10;

	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
}

void	test_copyConstructor() {
	std::cout << YELLOW << "[Test] Copy Constructor\n" << RESET;
	Array<std::string>	original(2);
	original[0] = "Hello";
	original[1] = "World";

	Array<std::string>	copy(original);
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
}

void	test_copyAssignment() {
	std::cout << YELLOW << "[Test] Copy Assignment\n" << RESET;
	Array<float>	a(3);
	a[0] = 1.1f;
	a[1] = 2.2f;
	a[2] = 3.3f;

	Array<float>	b;
	b = a;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;
}

void	test_boundsChecking() {
	std::cout << YELLOW << "[Test] Bounds Checking\n" << RESET;
	Array<int>	arr(3);
	try {
		arr[5] = 100;
	}
	catch (const std::exception &e) {
		std::cout << RED << "Caught exception: " << e.what() << RESET << std::endl;
	}
}

void	run_tests()
{
	void	(*tests[])() = \
	{
		test_defaultConstructor,
		test_parameterizedConstructor,
		test_copyConstructor,
		test_copyAssignment,
		test_boundsChecking
	};

	int	numTests = sizeof(tests) / sizeof(tests[0]);

	std::cout << "Running " << numTests << " tests...\n\n";
	for (int i = 0; i < numTests; i++)
	{
		tests[i]();
		std::cout << BLUE << "-------------------------------------------" << RESET << std::endl;
	}
}
