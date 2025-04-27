/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:03:28 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/27 15:08:40 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

template<typename T>
void	printContainer(T& container)
{
	typename T::iterator lastComma = --container.end();

	std::cout << "{";
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it;
		if (it != lastComma)
			std::cout << ",";
	}
	std::cout << "}\n";
}

template<typename T>
void printContainer(const T& container)
{
	typedef typename T::const_iterator const_iterator;
	const_iterator lastComma = --container.end();

	std::cout << "{";
	for (const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it;
		if (it != lastComma)
			std::cout << ",";
	}
	std::cout << "}\n";
}

void test_defaultConstructor()
{
	std::cout << YELLOW << "[Test] Default Constructor" << RESET << "\n";
	MutantStack<int> mstack;
	std::cout << "Size: " << mstack.size() << "\n\n";
}

void test_copyConstructor()
{
	std::cout << YELLOW << "[Test] Copy Constructor" << RESET << "\n";
	MutantStack<int> original;
	original.push(42);
	original.push(84);
	MutantStack<int> copy(original);

	std::cout << "Original top: " << original.top() << "\n";
	std::cout << "Copy top: " << copy.top() << "\n\n";
}

void test_copyAssignment()
{
	std::cout << YELLOW << "[Test] Copy Assignment" << RESET << "\n";
	MutantStack<int> original;
	original.push(10);
	original.push(20);
	MutantStack<int> assigned;
	assigned = original;

	std::cout << "Original size: " << original.size() << "\n";
    std::cout << "Original top: " << original.top() << "\n";
	std::cout << "Assigned size: " << assigned.size() << "\n";
	std::cout << "Assigned top: " << assigned.top() << "\n\n";
}

void test_iterators()
{
	std::cout << YELLOW << "[Test] Iterators" << RESET << "\n";
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);

    std::cout << "Stack contents: ";
    printContainer(mstack);

	std::cout << "Forward iteration:\n";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n\n";
}

void test_constIterators()
{
	std::cout << YELLOW << "[Test] Const Iterators" << RESET << "\n";
	MutantStack<int> mstack;
	mstack.push(7);
	mstack.push(8);
	mstack.push(9);

	const MutantStack<int> const_mstack(mstack);
    std::cout << "Stack contents: ";
    printContainer(const_mstack);

	std::cout << "Const forward iteration:\n";
	for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\n\n";
}

void test_reverseIterators()
{
	std::cout << YELLOW << "[Test] Reverse Iterators" << RESET << "\n";
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

    std::cout << "Stack contents: ";
    printContainer(mstack);

	std::cout << "Reverse iteration:\n";
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << "\n\n";
}

void test_subjectPDF_stack()
{
    std::cout << YELLOW << "[Test] Subject PDF Stack" << RESET << "\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top Element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Stack contents:\n";
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "\n";
}

void test_subjectPDF_list()
{
    std::cout << YELLOW << "[Test] Subject PDF Stack" << RESET << "\n";
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << "Last element: " << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "List contents:\n";
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "\n";
}

void	run_tests()
{
	void (*tests[])() = \
	{
		test_defaultConstructor,
		test_copyConstructor,
		test_copyAssignment,
        test_iterators,
        test_constIterators,
        test_reverseIterators,
        test_subjectPDF_stack,
        test_subjectPDF_list,
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
