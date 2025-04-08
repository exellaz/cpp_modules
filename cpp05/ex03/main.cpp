/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:41:54 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/08 08:24:32 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <typeinfo>
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

// bool	test_Intern_makeForm()
// {
// 	Intern	intern;
// 	AForm	*form;

// 	form = intern.makeForm("PresidentialPardonForm", "Amongus");
// 	form->action();
// 	return (true);
// }

bool	test_Intern_MakeForm_Shrubbery()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	formName = "ShruberryCreationForm";
		const std::string	target = "garden";

		Intern	intern;
		AForm	*form = intern.makeForm(formName, target);

		CHECK(formName, form->getName());
		CHECK(target, form->getTarget());
		CHECK(typeid(*form).name(), typeid(ShruberryCreationForm).name());

		delete form;
	}
	REPORT(result, "Intern MakeForm - Shrubbery Form");
	return (result);
}

bool	test_Intern_makeForm()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedType = "ShruberryCreationForm";
		const std::string	expectedTarget = "tree_target";
		const std::string	expectedFileContent = \
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
		const std::string	expectedException = "";

		Intern					intern;
		Bureaucrat				bureaucrat("TreeMan", 1);
		std::string				exceptionCaught;
		std::ifstream			infile;
		std::ostringstream		fileContents;
		AForm					*form;

		std::cout.rdbuf(NULL);
		try
		{
			form = intern.makeForm(expectedType, expectedTarget);
			form->beSigned(bureaucrat);
			bureaucrat.executeForm(*form);
		}
		catch (...)
		{
			exceptionCaught = "Exception occurred";
		}
		std::cout.rdbuf(originalCout);
		infile.open("tree_target_shruberry");
		fileContents << infile.rdbuf();
		std::remove("tree_target_shruberry");

		CHECK(expectedType, form->getName());
		CHECK(expectedTarget, form->getTarget());
		CHECK(expectedFileContent, fileContents.str());
		CHECK_EXCEPTION(expectedException, exceptionCaught);

		delete form;
	}
	{
		const std::string	expectedType = "RobotomyRequestForm";
		const std::string	expectedTarget = "victim";
		const std::string	expectedOutput = "Bob couldn't execute RobotomyRequestForm because grade is too low\n";

		Intern					intern;
		Bureaucrat				bureaucrat("Bob", 46);
		std::ostringstream		captureOutput;
		std::string				output;
		AForm					*form;

		std::cout.rdbuf(NULL);
		form = intern.makeForm(expectedType, expectedTarget);
		std::cout.rdbuf(captureOutput.rdbuf());
		form->beSigned(bureaucrat);
		bureaucrat.executeForm(*form);
		std::cout.rdbuf(originalCout);

		output = captureOutput.str();
		CHECK(expectedType, form->getName());
		CHECK(expectedTarget, form->getTarget());
		CHECK(expectedOutput, output);

		delete form;
	}
	{
		const std::string	expectedOutput = "Cannot find form of InvalidFormName\n";

		Intern					intern;
		std::ostringstream		captureOutput;
		std::string				output;
		AForm					*form;

		std::cout.rdbuf(captureOutput.rdbuf());
		form = intern.makeForm("InvalidFormName", "some_target");
		std::cout.rdbuf(originalCout);

		output = captureOutput.str();
		CHECK(0, form);
		CHECK(expectedOutput, output);
	}
	REPORT(result, "Intern makeForm test");
	return (result);
}


void	run_tests()
{
	int		passed = 0;
	int		failed = 0;
	bool	(*tests[])() = \
	{
		test_Intern_makeForm,
		// test_Intern_MakeForm_Shrubbery,
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
