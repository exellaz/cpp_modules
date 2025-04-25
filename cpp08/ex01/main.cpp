/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:56:43 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/25 14:37:40 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

# define GREEN   "\033[32m"
# define RED     "\033[31m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define RESET   "\033[0m"

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

void test_defaultConstructor()
{
	std::cout << YELLOW << "[Test] Default Constructor" << RESET << "\n";
	Span span;
	std::cout << "Max Size: " << span.getMaxSize() << "\n\n";
}

void test_parameterizedConstructor()
{
	std::cout << YELLOW << "[Test] Parameterized Constructor" << RESET << "\n";
	Span span(3);
	std::cout << "Max Size: " << span.getMaxSize() << "\n\n";
}

void test_copyConstructor()
{
	std::cout << YELLOW << "[Test] Copy Constructor" << RESET << "\n";
	Span original(3);
	original.addNumber(10);
	original.addNumber(20);
	Span copy(original);

	std::cout << "Original numbers: ";
	printContainer(original.getNumbers());
	std::cout << "Original max size: " << original.getMaxSize() << "\n\n";

	std::cout << "Copied numbers: ";
	printContainer(copy.getNumbers());
	std::cout << "Copy max size: " << copy.getMaxSize() << "\n\n";
}

void test_copyAssignment()
{
	std::cout << YELLOW << "[Test] Copy Assignment Operator" << RESET << "\n";
	Span original(2);
	original.addNumber(5);
	original.addNumber(15);
	Span copy(5);
	copy = original;

	std::cout << "Original numbers: ";
	printContainer(original.getNumbers());
	std::cout << "Original max size: " << original.getMaxSize() << "\n\n";

	std::cout << "Copied numbers: ";
	printContainer(copy.getNumbers());
	std::cout << "Copy max size: " << copy.getMaxSize() << "\n\n";
}

void test_addNumber()
{
	std::cout << YELLOW << "[Test] addNumber" << RESET << "\n";
	{
		Span span(4);
		span.addNumber(2);
		span.addNumber(8);
		span.addNumber(1);
		span.addNumber(3);

		std::cout << "Added numbers: 2, 8, 1, 3\n";
		std::cout << "Numbers: ";
		printContainer(span.getNumbers());
		std::cout << "\n";
	}
	{
		Span span(2);
		try {
			span.addNumber(1);
			span.addNumber(2);
			std::cout << "Adding 3 numbers into Span with max size of 2...\n";
			span.addNumber(3);
		}
		catch (const std::exception& e) {
			std::cout << "Exception (addNumber): " << e.what() << "\n\n";
		}
	}
}

void test_shortestSpan()
{
	std::cout << YELLOW << "[Test] shortestSpan" << RESET << "\n";
	{
		Span span(5);
		span.addNumber(3);
		span.addNumber(9);
		span.addNumber(6);
		span.addNumber(1);

		std::cout << "Numbers: ";
		printContainer(span.getNumbers());
		std::cout << "Shortest Span: " << span.shortestSpan() << "\n\n";
	}
	{
		try {
			Span smallSpan(1);
			smallSpan.addNumber(1);
			std::cout << "Calling shortestSpan on insufficient data...\n";
			smallSpan.shortestSpan();
		}
		catch (const std::exception& e) {
			std::cout << "Exception (shortestSpan): " << e.what() << "\n\n";
		}
	}
}

void test_longestSpan()
{
	std::cout << YELLOW << "[Test] longestSpan" << RESET << "\n";
	{
		Span span(5);
		span.addNumber(10);
		span.addNumber(42);
		span.addNumber(1);
		span.addNumber(17);

		std::cout << "Numbers: ";
		printContainer(span.getNumbers());
		std::cout << "Longest Span: " << span.longestSpan() << "\n\n";
	}
	{
		try {
			Span smallSpan(1);
			smallSpan.addNumber(1);
			std::cout << "Calling longestSpan on insufficient data...\n";
			smallSpan.longestSpan();
		}
		catch (const std::exception& e) {
			std::cout << "Exception (longestSpan): " << e.what() << "\n\n";
		}
	}
}

void	test_subjectPDF()
{
	std::cout << YELLOW << "[Test] Subject PDF" << RESET << "\n";
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	run_tests()
{
	void (*tests[])() = \
	{
		test_defaultConstructor,
		test_parameterizedConstructor,
		test_copyConstructor,
		test_copyAssignment,
		test_addNumber,
		test_shortestSpan,
		test_longestSpan,
		test_subjectPDF,
	};

	int	numTests = sizeof(tests) / sizeof(tests[0]);

	std::cout << "Running " << numTests << " tests...\n\n";
	for (int i = 0; i < numTests; i++)
	{
		tests[i]();
		std::cout << BLUE << "-------------------------------------------" << RESET << "\n";
	}
}

int main()
{
	run_tests();
	return 0;
}
