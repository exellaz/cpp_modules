/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:41:54 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/03/24 11:53:28 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <sstream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

#define REPORT(condition, msg) \
	if (!result) \
		std::cerr << RED << errors.str() << RESET; \
	if (!(condition)) \
	{ \
		std::cerr << RED "[FAILED] " << msg RESET << " (" \
			<< __FILE__ << ":" << __LINE__ << ")" << std::endl; \
		return false; \
	} \
	else \
	{ \
		std::cout << GREEN "[PASSED] " << msg RESET << std::endl; \
	}

#define CHECK(expected, received) \
	if (received != expected) \
	{ \
		errors << "[FAILED] Expected: `" << expected << "`, got `" \
			<< received << "`\n"; \
		result = false; \
	}

#define CHECK_EXCEPTION(expected, received) \
	{ \
		if (received != expected) \
		{ \
			errors << "[FAILED] Expected exception: `" << expected; \
			if (received.empty()) \
				errors << "`, no exception thrown\n"; \
			else \
				errors << "`, got `" << received << "`\n"; \
			result = false; \
		} \
	}

void	run_tests();

int	main()
{
	run_tests();
	return 0;
}

bool	test_Bureaucrat_DefaultConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "John Doe";
		const int			expectedGrade = 150;
		Bureaucrat			b;
		std::string			name = b.getName();
		int					grade = b.getGrade();

		CHECK(expectedName, name);
		CHECK(expectedGrade, grade);
	}
	REPORT(result, "Default constructor test");
	return (result);
}

bool	test_Bureaucrat_ParameterizedConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "Duck";
		const int			expectedGrade = 100;
		Bureaucrat			b(expectedName, expectedGrade);
		Bureaucrat			c(b);
		std::string			name = c.getName();
		int					grade = c.getGrade();

		CHECK(expectedName, name);
		CHECK(expectedGrade, grade);
	}
	REPORT(result, "Parameterized constructor test");
	return (result);
}

bool	test_Bureaucrat_CopyConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "Blop";
		const int			expectedGrade = 120;
		Bureaucrat			b(expectedName, expectedGrade);
		Bureaucrat			c(b);
		std::string			name = c.getName();
		int					grade = c.getGrade();

		CHECK(expectedName, name);
		CHECK(expectedGrade, grade);
	}
	REPORT(result, "Copy constructor test");
	return (result);
}

bool	test_Bureaucrat_CopyAssignmentOperator()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "Monty";
		const int			expectedGrade = 120;
		Bureaucrat			b(expectedName, expectedGrade);
		Bureaucrat			c;

		c = b;
		int			grade = c.getGrade();

		CHECK(expectedGrade, grade);
	}
	REPORT(result, "Copy assignment operator test");
	return (result);
}

bool	test_Bureaucrat_InsertionOperator()
{
	std::ostringstream	buffer;
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedString = "John Doe, bureaucrat grade 150.";
		Bureaucrat			b;
		std::string			string;

		buffer << b;
		string = buffer.str();
		CHECK(expectedString, string);
	}
	REPORT(result, "Insertion operator test");
	return (result);
}

bool	test_Bureaucrat_GradeTooHighException()
{
	const std::string	expectedException = "Bureaucrat::GradeTooHighException";
	std::ostringstream	errors;
	std::string			exceptionCaught;
	bool				result = true;

	try
	{
		Bureaucrat	b("Bob", 0);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		exceptionCaught = "Bureaucrat::GradeTooHighException";
		std::cout << e.what() << "\n";
	}
	CHECK_EXCEPTION(expectedException, exceptionCaught);
	REPORT(result, "GradeTooHigh exception test");
	return (result);
}

bool	test_Bureaucrat_GradeTooLowException()
{
	const std::string	expectedException = "Bureaucrat::GradeTooLowException";
	std::ostringstream	errors;
	std::string			exception_caught;
	bool				result = true;

	try
	{
		Bureaucrat	b("Bub", 151);
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		exception_caught = "Bureaucrat::GradeTooLowException";
		std::cout << e.what() << "\n";
	}
	CHECK_EXCEPTION(expectedException, exception_caught);
	REPORT(result, "GradeTooLow exception test");
	return (result);
}

bool	test_Bureaucrat_IncrementGrade()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const int	expectedGrade = 1;
		int			grade;
		Bureaucrat	b("David", 2);

		b.incrementGrade();
		grade = b.getGrade();
		CHECK(expectedGrade, grade);
	}
	{
		const std::string	expectedException = "Bureaucrat::GradeTooHighException";
		Bureaucrat			c("Nick", 1);
		std::string			exception_caught;
		try
		{
			c.incrementGrade();
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			exception_caught = "Bureaucrat::GradeTooHighException";
			std::cout << e.what() << "\n";
		}
		CHECK_EXCEPTION(expectedException, exception_caught);
	}
	REPORT(result, "IncrementGrade test");
	return (result);
}

bool	test_Bureaucrat_DecrementGrade()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const int	expectedGrade = 2;
		int			grade;
		Bureaucrat	b("Lynn", 1);

		b.decrementGrade();
		grade = b.getGrade();
		CHECK(expectedGrade, grade);
	}
	{
		const std::string	expectedException = "Bureaucrat::GradeTooLowException";
		std::string			exception_caught;
		Bureaucrat			c("Cat", 150);
		try
		{
			c.decrementGrade();
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			exception_caught = "Bureaucrat::GradeTooLowException";
			std::cout << e.what() << "\n";
		}
		CHECK_EXCEPTION(expectedException, exception_caught);
	}
	REPORT(result, "DecrementGrade test");
	return (result);
}

void	run_tests()
{
	int		passed = 0;
	int		failed = 0;
	bool	(*tests[])() = \
	{
		test_Bureaucrat_DefaultConstructor,
		test_Bureaucrat_ParameterizedConstructor,
		test_Bureaucrat_CopyConstructor,
		test_Bureaucrat_CopyAssignmentOperator,
		test_Bureaucrat_InsertionOperator,
		test_Bureaucrat_GradeTooHighException,
		test_Bureaucrat_GradeTooLowException,
		test_Bureaucrat_IncrementGrade,
		test_Bureaucrat_DecrementGrade,
	};

	int	numTests = sizeof(tests) / sizeof(tests[0]);

	std::cout << "Running " << numTests << " tests...\n\n";
	for (int i = 0; i < numTests; i++)
	{
		if (tests[i]())
			passed++;
		else
			failed++;
		std::cout << "-------------------------------------------" << std::endl;
	}
	std::cout << "\nTests passed: " << passed << " / " << numTests << std::endl;
	std::cout << "Tests failed: " << failed << " / " << numTests << std::endl;
}
