/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:41:54 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/03/28 21:45:31 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
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

bool test_Shruberry_DefaultConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "ShruberryCreationForm";
		const std::string	expectedTarget = "default target";
		const bool			expectedStatus = false;
		const int			expectedGradeToSign = 145;
		const int			expectedGradeToExecute = 137;

		ShruberryCreationForm	form;
		std::string			name = form.getName();
		std::string			target = form.getTarget();
		bool				status = form.getSigned();
		int					gradeToSign = form.getGradeToSign();
		int					gradeToExecute = form.getGradeToExecute();

		CHECK(expectedName, name);
		CHECK(expectedTarget, target);
		CHECK(expectedStatus, status);
		CHECK(expectedGradeToSign, gradeToSign);
		CHECK(expectedGradeToExecute, gradeToExecute);
	}
	REPORT(result, "Shruberry default constructor test");
	return (result);
}

bool test_Shruberry_ParameterizedConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "ShruberryCreationForm";
		const std::string	expectedTarget = "custom target";
		const bool			expectedStatus = false;
		const int			expectedGradeToSign = 145;
		const int			expectedGradeToExecute = 137;

		ShruberryCreationForm	form(expectedTarget);
		std::string				name = form.getName();
		std::string				target = form.getTarget();
		bool					status = form.getSigned();
		int						gradeToSign = form.getGradeToSign();
		int						gradeToExecute = form.getGradeToExecute();

		CHECK(expectedName, name);
		CHECK(expectedTarget, target);
		CHECK(expectedStatus, status);
		CHECK(expectedGradeToSign, gradeToSign);
		CHECK(expectedGradeToExecute, gradeToExecute);
	}
	REPORT(result, "Shruberry Parameterized constructor test");
	return (result);
}

bool test_Shruberry_CopyConstructor()
{
	std::ostringstream errors;
	bool result = true;

	{
		const std::string expectedTarget = "copy target";

		ShruberryCreationForm original(expectedTarget);
		ShruberryCreationForm copy(original);

		CHECK(original.getName(), copy.getName());
		CHECK(original.getTarget(), copy.getTarget());
		CHECK(original.getSigned(), copy.getSigned());
		CHECK(original.getGradeToSign(), copy.getGradeToSign());
		CHECK(original.getGradeToExecute(), copy.getGradeToExecute());
	}
	REPORT(result, "Shruberry copy constructor test");
	return (result);
}

bool	test_Shruberry_AssignmentOperator()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string expectedTarget = "assigned target";

		ShruberryCreationForm original(expectedTarget);
		ShruberryCreationForm assigned("temp");
		assigned = original;

		CHECK(original.getSigned(), assigned.getSigned());
	}
	REPORT(result, "Shruberry assignment operator Test");
	return (result);
}

bool test_Shruberry_Action()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedException = "AForm::GradeTooLowException";

		ShruberryCreationForm	form("tree_target");
		Bureaucrat				bureaucrat("lowGrade", 150);

		std::string	exceptionCaught;
		try
		{
			form.beSigned(bureaucrat);
		}
		catch (const AForm::GradeTooLowException &e)
		{
			exceptionCaught = "AForm::GradeTooLowException";
		}
		CHECK_EXCEPTION(expectedException, exceptionCaught);
	}
	{
		std::string			expectedException = "";
		std::stringstream	expectedContent;
		expectedContent <<	"     ccee88oo\n"
							"  C8O8O8Q8PoOb o8oo\n"
							" dOB69QO8PdUOpugoO9bD\n"
							"CgggbU8OU qOp qOdoUOdcb\n"
							"    6OuU  /p u gcoUodpP\n"
							"      \\\\\\//  /douUP\n"
							"        \\\\\\////\n"
							"         |||/\\\n"
							"         |||\\/\n"
							"         |||||\n"
							"   .....//||||\\....";

		ShruberryCreationForm	form("tree_target");
		Bureaucrat				bureaucrat("sufficientGrade", 138);
		std::ifstream			infile;
		std::ostringstream		content;

		std::string	exceptionCaught;
		try
		{
			form.beSigned(bureaucrat);
			form.execute(bureaucrat);
		}
		catch (...)
		{
			exceptionCaught = "Something went wrong";
		}
		infile.open("tree_target_shruberry");
		content << infile.rdbuf();

		CHECK(expectedContent.str(), content.str());
		CHECK_EXCEPTION(expectedException, exceptionCaught);
	}
	REPORT(result, "Shruberry action method Test");
	return (result);
}


void	run_tests()
{
	int		passed = 0;
	int		failed = 0;
	bool	(*tests[])() = \
	{
		test_Shruberry_DefaultConstructor,
		test_Shruberry_ParameterizedConstructor,
		test_Shruberry_CopyConstructor,
		test_Shruberry_AssignmentOperator,
		test_Shruberry_Action,
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
