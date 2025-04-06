/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:41:54 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/06 14:56:43 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
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

std::streambuf	*originalCout = std::cout.rdbuf();

void	run_tests();

int	main()
{
	run_tests();
	return 0;
}

bool	test_Bureaucrat_executeForm()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedOutput = "Timmy couldn't execute RobotomyRequestForm " \
											 "because grade is too low\n";

		Bureaucrat			lowGrade("Timmy", 72);
		RobotomyRequestForm	form("target");
		std::ostringstream	captureOutput;
		std::string 		output;

		std::cout.rdbuf(captureOutput.rdbuf());
		form.beSigned(lowGrade);
		lowGrade.executeForm(form);
		std::cout.rdbuf(originalCout);
		output = captureOutput.str();

		CHECK(expectedOutput, output);
	}
	{
		const std::string	expectedException = "";
		const std::string	expectedContent = \
								"     ccee88oo\n"
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
		Bureaucrat				bureaucrat("Bob", 1);
		std::string				exceptionCaught;
		std::ifstream			infile;
		std::ostringstream		content;

		std::cout.rdbuf(NULL);
		try
		{
			form.beSigned(bureaucrat);
			bureaucrat.executeForm(form);
		}
		catch (...)
		{
			exceptionCaught = "Something went wrong";
		}
		std::cout.rdbuf(originalCout);
		infile.open("tree_target_shruberry");
		content << infile.rdbuf();
		std::remove("tree_target_shruberry");

		CHECK(expectedContent, content.str());
		CHECK_EXCEPTION(expectedException, exceptionCaught);
	}
	REPORT(result, "Bureaucrat executeForm test");
	return (result);
}

bool	test_Shruberry_DefaultConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "ShruberryCreationForm";
		const std::string	expectedTarget = "default_target";
		const bool			expectedStatus = false;
		const int			expectedGradeToSign = 145;
		const int			expectedGradeToExecute = 137;

		ShruberryCreationForm	form;
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
	REPORT(result, "Shruberry default constructor test");
	return (result);
}

bool	test_Shruberry_ParameterizedConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "ShruberryCreationForm";
		const std::string	expectedTarget = "custom_target";
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
	REPORT(result, "Shruberry parameterized constructor test");
	return (result);
}

bool	test_Shruberry_CopyConstructor()
{
	std::ostringstream errors;
	bool result = true;

	{
		const std::string expectedTarget = "copy_target";

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
		const std::string expectedTarget = "assigned_target";

		ShruberryCreationForm original(expectedTarget);
		ShruberryCreationForm assigned("temp");
		assigned = original;

		CHECK(original.getSigned(), assigned.getSigned());
	}
	REPORT(result, "Shruberry assignment operator Test");
	return (result);
}

bool	test_Shruberry_Action()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedContent = \
								"     ccee88oo\n"
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

		const std::string		target = "tree_target";
		ShruberryCreationForm	form(target);
		std::ifstream			infile;
		std::ostringstream		content;

		form.action();
		infile.open("tree_target_shruberry");
		content << infile.rdbuf();
		infile.close();
		std::remove("tree_target_shruberry");

		CHECK(expectedContent, content.str());
	}
	REPORT(result, "Shruberry action method test");
	return (result);
}

bool	test_Robotomy_DefaultConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "RobotomyRequestForm";
		const std::string	expectedTarget = "default_target";
		const bool			expectedStatus = false;
		const int			expectedGradeToSign = 72;
		const int			expectedGradeToExecute = 45;

		RobotomyRequestForm	form;
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
	REPORT(result, "Robotomy default constructor test");
	return (result);
}

bool	test_Robotomy_ParameterizedConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "RobotomyRequestForm";
		const std::string	expectedTarget = "custom_target";
		const bool			expectedStatus = false;
		const int			expectedGradeToSign = 72;
		const int			expectedGradeToExecute = 45;

		RobotomyRequestForm	form(expectedTarget);
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
	REPORT(result, "Robotomy parameterized constructor test");
	return (result);
}

bool	test_Robotomy_CopyConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedTarget = "copy_target";

		RobotomyRequestForm	original(expectedTarget);
		RobotomyRequestForm	copy(original);

		CHECK(original.getName(), copy.getName());
		CHECK(original.getTarget(), copy.getTarget());
		CHECK(original.getSigned(), copy.getSigned());
		CHECK(original.getGradeToSign(), copy.getGradeToSign());
		CHECK(original.getGradeToExecute(), copy.getGradeToExecute());
	}
	REPORT(result, "Robotomy copy constructor test");
	return (result);
}

bool	test_Robotomy_AssignmentOperator()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedTarget = "assigned_target";

		RobotomyRequestForm	original(expectedTarget);
		RobotomyRequestForm	assigned("temp");
		assigned = original;

		CHECK(original.getSigned(), assigned.getSigned());
	}
	REPORT(result, "Robotomy assignment operator test");
	return (result);
}

bool test_Robotomy_Action()
{
	std::ostringstream errors;
	bool result = true;

	{
		const std::string	target = "robo_target";
		RobotomyRequestForm	form(target);
		std::ostringstream	captureOutput;
		std::string			output;

		std::cout.rdbuf(captureOutput.rdbuf());
		form.action();
		std::cout.rdbuf(originalCout);
		output = captureOutput.str();

		bool containsDrill = output.find("* drilling noises *") != std::string::npos;
		bool containsSuccess = output.find(target + " has been robotomized successfully.") != std::string::npos;
		bool containsFailure = output.find("Robotomy of " + target + " failed.") != std::string::npos;

		CHECK(true, (containsDrill && (containsSuccess || containsFailure)))
	}
	REPORT(result, "Robotomy action test");
	return (result);
}

void	run_tests()
{
	int		passed = 0;
	int		failed = 0;
	bool	(*tests[])() = \
	{
		test_Bureaucrat_executeForm,
		test_Shruberry_DefaultConstructor,
		test_Shruberry_ParameterizedConstructor,
		test_Shruberry_CopyConstructor,
		test_Shruberry_AssignmentOperator,
		test_Shruberry_Action,
		test_Robotomy_DefaultConstructor,
		test_Robotomy_ParameterizedConstructor,
		test_Robotomy_CopyConstructor,
		test_Robotomy_AssignmentOperator,
		test_Robotomy_Action,
		
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
