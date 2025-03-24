/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:41:54 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/03/24 15:02:32 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
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

bool	test_Form_DefaultConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "default";
		const bool			expectedStatus = false;
		const int			expectedGradeToSign = 150;
		const int			expectedGradeToExecute = 1;

		Form				form;
		std::string			name = form.getName();
		bool				status = form.getSigned();
		int					gradeToSign = form.getGradeToSign();
		int					gradeToExecute = form.getGradeToExecute();

		CHECK(expectedName, name);
		CHECK(expectedStatus, status);
		CHECK(expectedGradeToSign, gradeToSign);
		CHECK(expectedGradeToExecute, gradeToExecute);
	}
	REPORT(result, "Default constructor test");
	return (result);
}

bool	test_Form_ParameterizedConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "Params";
		const bool			expectedStatus = false;
		const int			expectedGradeToSign = 100;
		const int			expectedGradeToExecute = 50;

		Form		form("Params", 100, 50);
		std::string	name = form.getName();
		bool		status = form.getSigned();
		int			gradeToSign = form.getGradeToSign();
		int			gradeToExecute = form.getGradeToExecute();

		CHECK(expectedName, name);
		CHECK(expectedStatus, status);
		CHECK(expectedGradeToSign, gradeToSign);
		CHECK(expectedGradeToExecute, gradeToExecute);
	}
	REPORT(result, "Parameterized constructor test");
	return (result);
}

bool	test_Form_CopyConstructor()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "Copy";
		const bool			expectedStatus = false;
		const int			expectedGradeToSign = 100;
		const int			expectedGradeToExecute = 50;

		Form		form("Copy", 100, 50);
		Form		copyForm(form);
		std::string	name = copyForm.getName();
		bool		status = copyForm.getSigned();
		int			gradeToSign = copyForm.getGradeToSign();
		int			gradeToExecute = copyForm.getGradeToExecute();

		CHECK(expectedName, name);
		CHECK(expectedStatus, status);
		CHECK(expectedGradeToSign, gradeToSign);
		CHECK(expectedGradeToExecute, gradeToExecute);
	}
	REPORT(result, "Copy constructor test");
	return (result);
}

bool	test_Form_BeSigned()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const bool	expectedStatus = true;

		Form		form("Sign", 20, 5);
		Bureaucrat	b("highGrade", 20);

		form.beSigned(b);
		bool	status = form.getSigned();

		CHECK(expectedStatus, status);
	}
	{
		const std::string	expectedException = "Form::GradeTooLowException";

		Form		form("cantSign", 50, 5);
		Bureaucrat	b("lowGrade", 120);

		std::string	exceptionCaught;
		try
		{
			form.beSigned(b);
		}
		catch (Form::GradeTooLowException &e)
		{
			exceptionCaught = "Form::GradeTooLowException";
		}
		CHECK_EXCEPTION(expectedException, exceptionCaught);
	}
	REPORT(result, "beSigned test");
	return (result);
}

bool	test_Form_CopyAssignmentOperator()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedName = "Copy Assign";
		const bool			expectedStatus = true;
		const int			expectedGradeToSign = 100;
		const int			expectedGradeToExecute = 50;

		Form		form("CopyNot", 20, 5);
		Form		copyForm("Copy Assign", 100, 50);
		Bureaucrat	b("Llama", 1);
		form.beSigned(b);
		copyForm = form;

		std::string	name = copyForm.getName();
		bool		status = copyForm.getSigned();
		int			gradeToSign = copyForm.getGradeToSign();
		int			gradeToExecute = copyForm.getGradeToExecute();

		CHECK(expectedName, name);
		CHECK(expectedStatus, status);
		CHECK(expectedGradeToSign, gradeToSign);
		CHECK(expectedGradeToExecute, gradeToExecute);
	}
	REPORT(result, "Copy assignment test");
	return (result);
}

bool	test_Form_InsertionOperator()
{
	std::ostringstream	buffer;
	std::ostringstream	errors;
	bool				result = true;

	{
		const std::string	expectedString =
			"Form default is not signed yet. " \
			"Grade required to sign is 150. " \
			"Grade required to execute is 1.\n";

		Form		form;
		std::string	string;

		buffer << form;
		string = buffer.str();
		CHECK(expectedString, string);
	}
	REPORT(result, "Insertion operator test");
	return (result);
}

bool	test_Form_GradeTooHighException()
{
	std::ostringstream	errors;
	bool				result = true;
	const std::string	expectedException("Form::GradeTooHighException");

	{
		std::string	exceptionCaught;
		try
		{
			Form	form("signTooHigh", 0, 50);
		}
		catch (const Form::GradeTooHighException &e)
		{
			exceptionCaught = "Form::GradeTooHighException";
		}
		CHECK_EXCEPTION(expectedException, exceptionCaught);
	}
	{
		std::string	exceptionCaught;
		try
		{
			Form	form("execTooHigh", 50, 0);
		}
		catch (const Form::GradeTooHighException &e)
		{
			exceptionCaught = "Form::GradeTooHighException";
		}
		CHECK_EXCEPTION(expectedException, exceptionCaught);
	}
	REPORT(result, "GradeTooHighException test");
	return (result);
}

bool	test_Form_GradeTooLowException()
{
	std::ostringstream	errors;
	bool				result = true;
	const std::string	expectedException("Form::GradeTooLowException");

	{
		std::string	exceptionCaught;
		try
		{
			Form	form("signTooLow", 151, 50);
		}
		catch (const Form::GradeTooLowException &e)
		{
			exceptionCaught = "Form::GradeTooLowException";
		}
		CHECK_EXCEPTION(expectedException, exceptionCaught);
	}
	{
		std::string	exceptionCaught;
		try
		{
			Form	form("execTooLow", 50, 151);
		}
		catch (const Form::GradeTooLowException &e)
		{
			exceptionCaught = "Form::GradeTooLowException";
		}
		CHECK_EXCEPTION(expectedException, exceptionCaught);
	}
	REPORT(result, "GradeTooLowException test");
	return (result);
}

bool	test_Form_SignForm()
{
	std::ostringstream	errors;
	bool				result = true;

	{
		bool	expectedStatus = true;

		Form		form("signForm", 1, 1);
		Bureaucrat	b("Fed", 1);


		b.signForm(form);
		bool	status = form.getSigned();

		CHECK(expectedStatus, status);
	}
	{
		bool	expectedStatus = false;

		Form		form("SignForm", 1, 1);
		Bureaucrat	b("Meat", 150);

		b.signForm(form);
		bool	status = form.getSigned();

		CHECK(expectedStatus, status);
	}
		{
		const bool	expectedStatus = true;

		Form		form("Signed", 150, 150);
		Bureaucrat	b("Ham", 150);

		b.signForm(form);
		b.signForm(form);
		bool	status = form.getSigned();

		CHECK(expectedStatus, status);
	}
	REPORT(result, "SignForm test");
	return (result);
}

void	run_tests()
{
	int		passed = 0;
	int		failed = 0;
	bool	(*tests[])() = \
	{
		test_Form_DefaultConstructor,
		test_Form_ParameterizedConstructor,
		test_Form_CopyConstructor,
		test_Form_BeSigned,
		test_Form_CopyAssignmentOperator,
		test_Form_InsertionOperator,
		test_Form_GradeTooHighException,
		test_Form_GradeTooLowException,
		test_Form_SignForm,
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
