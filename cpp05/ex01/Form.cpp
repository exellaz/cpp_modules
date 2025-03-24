/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:44:12 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/03/24 10:25:00 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form()
	: _name("default"),
	_signed(false),
	_gradeToSign(150),
	_gradeToExecute(1)
{
	if (DEBUG == 1)
		std::cout << "Form default constructor called\n";
}

Form::~Form()
{
	if (DEBUG == 1)
		std::cout << "Form destructor called\n";
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
	else if (DEBUG == 1)
		std::cout << "Form parameterized constructor called\n";
}

Form::Form(const Form &src)
	: _name(src._name),
	_signed(src._signed),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{
	if (DEBUG == 1)
		std::cout << "Form copy constructor called\n";
}

Form	&Form::operator=(const Form &src)
{
	if (this != &src)
		_signed = src._signed;
	if (DEBUG == 1)
		std::cout << "Form copy assignment operator called\n";
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
	if (bureaucrat.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw Form::GradeTooLowException();

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

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
