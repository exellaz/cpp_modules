/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:44:12 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/03/25 15:39:11 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

Form::Form()
	: _name("default"),
	_signed(false),
	_gradeToSign(150),
	_gradeToExecute(1)
{
	printMsg("Form default constructor called\n");
}

Form::~Form()
{
	printMsg("Form destructor called\n");
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute)
	: _name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	printMsg("Form parameterized constructor called\n");
}

Form::Form(const Form &src)
	: _name(src._name),
	_signed(src._signed),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{
	printMsg("Form copy constructor called\n");
}

Form	&Form::operator=(const Form &src)
{
	if (this != &src)
		_signed = src._signed;
	printMsg("Form copy assignment operator called\n");
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const Form &src)
{
	stream << "Form " << src.getName();
	if (src.getSigned() == false)
		stream << " is not signed yet. ";
	else
		stream << " is signed. ";
	stream << "Grade required to sign is " << src.getGradeToSign() << ". ";
	stream << "Grade required to execute is " << src.getGradeToExecute() << ".\n";
	return (stream);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;

}

const std::string &Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	printMsg(std::string str)
{
	if (DEBUG == 1)
		std::cout << str;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}
