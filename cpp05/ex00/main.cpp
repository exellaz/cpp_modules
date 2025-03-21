/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:41:54 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/03/21 20:11:53 by kkhai-ki         ###   ########.fr       */
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

void	run_tests(void);

int	main(void)
{
	run_tests();
	return 0;
}

bool	test_Bureaucrat_DefaultConstructor(void)
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expected_name = "John Doe";
		const int			expected_grade = 150;
		Bureaucrat			b;
		std::string			name = b.getName();
		int					grade = b.getGrade();

		CHECK(expected_name, name);
		CHECK(expected_grade, grade);
	}
	REPORT(result, "Default constructor test");
	return (result);
}

bool	test_Bureaucrat_ParameterizedConstructor(void)
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expected_name = "Duck";
		const int			expected_grade = 100;
		Bureaucrat			b(expected_name, expected_grade);
		Bureaucrat			c(b);
		std::string			name = c.getName();
		int					grade = c.getGrade();

		CHECK(expected_name, name);
		CHECK(expected_grade, grade);
	}
	REPORT(result, "Parameterized constructor test");
	return (result);
}

bool	test_Bureaucrat_CopyConstructor(void)
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expected_name = "Blop";
		const int			expected_grade = 120;
		Bureaucrat			b(expected_name, expected_grade);
		Bureaucrat			c(b);
		std::string			name = c.getName();
		int					grade = c.getGrade();

		CHECK(expected_name, name);
		CHECK(expected_grade, grade);
	}
	REPORT(result, "Copy constructor test");
	return (result);
}

bool	test_Bureaucrat_CopyAssignmentOperator(void)
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expected_name = "Monty";
		const int			expected_grade = 120;
		Bureaucrat	b(expected_name, expected_grade);
		Bureaucrat	c = b;
		int			grade = c.getGrade();

		CHECK(expected_grade, grade);
	}
	REPORT(result, "Copy assignment operator test");
	return (result);
}

bool	test_Bureaucrat_InsertionOperator(void)
{
	std::ostringstream	buffer;
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expected_string = "John Doe, bureaucrat grade 150.";
		Bureaucrat	b;
		std::string	string;

		buffer << b;
		string = buffer.str();
		CHECK(expected_string, string);
	}
	REPORT(result, "Insertion operator test");
	return (result);
}

bool	test_Bureaucrat_GradeTooHighException(void)
{
	const std::string	expected_exception = "Bureaucrat::GradeTooHighException";
	std::ostringstream	errors;
	std::string			exception_caught;
	bool				result = true;

	try
	{
		Bureaucrat	b("Bob", 0);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		exception_caught = "Bureaucrat::GradeTooHighException";
	}
	CHECK_EXCEPTION(expected_exception, exception_caught);
	REPORT(result, "GradeTooHigh exception test");
	return (result);
}

bool	test_Bureaucrat_GradeTooLowException(void)
{
	const std::string	expected_exception = "Bureaucrat::GradeTooLowException";
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
	}
	CHECK_EXCEPTION(expected_exception, exception_caught);
	REPORT(result, "GradeTooLow exception test");
	return (result);
}

bool	test_Bureaucrat_IncrementGrade(void)
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const int	expected_grade = 1;
		int			grade;
		Bureaucrat	b("David", 2);

		b.incrementGrade();
		grade = b.getGrade();
		CHECK(expected_grade, grade);
	}
	{
		const std::string	expected_exception = "Bureaucrat::GradeTooHighException";
		Bureaucrat			c("Nick", 1);
		std::string			exception_caught;
		try
		{
			c.incrementGrade();
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			exception_caught = "Bureaucrat::GradeTooHighException";
		}
		CHECK_EXCEPTION(expected_exception, exception_caught);
	}
	REPORT(result, "IncrementGrade test");
	return (result);
}

bool	test_Bureaucrat_DecrementGrade(void)
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const int	expected_grade = 2;
		int			grade;
		Bureaucrat	b("Lynn", 1);

		b.decrementGrade();
		grade = b.getGrade();
		CHECK(expected_grade, grade);
	}
	{
		const std::string	expected_exception = "Bureaucrat::GradeTooLowException";
		std::string			exception_caught;
		Bureaucrat			c("Cat", 150);
		try
		{
			c.decrementGrade();
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			exception_caught = "Bureaucrat::GradeTooLowException";
		}
		CHECK_EXCEPTION(expected_exception, exception_caught);
	}
	REPORT(result, "DecrementGrade test");
	return (result);
}

void	run_tests(void)
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

	int	num_tests = sizeof(tests) / sizeof(tests[0]);

	std::cout << "Running " << num_tests << " tests...\n\n";
	for (int i = 0; i < num_tests; i++)
	{
		if (tests[i]())
			passed++;
		else
			failed++;
		std::cout << "-------------------------------------------" << std::endl;
	}
	std::cout << "\nTests passed: " << passed << " / " << num_tests << std::endl;
	std::cout << "Tests failed: " << failed << " / " << num_tests << std::endl;
}
