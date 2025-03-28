/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:44:12 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/03/28 21:01:32 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm()
	: _name("default"),
	_target("default target"),
	_signed(false),
	_gradeToSign(150),
	_gradeToExecute(1)
{
	printMsg("AForm default constructor called\n");
}

AForm::~AForm()
{
	printMsg("AForm destructor called\n");
}

AForm::AForm(const std::string &name, const std::string &target, \
	const int gradeToSign, const int gradeToExecute)
	: _name(name),
	_target(target),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	printMsg("AForm parameterized constructor called\n");
}

AForm::AForm(const AForm &src)
	: _name(src._name),
	_target(src._target),
	_signed(src._signed),
	_gradeToSign(src._gradeToSign),
	_gradeToExecute(src._gradeToExecute)
{
	printMsg("AForm copy constructor called\n");
}

AForm	&AForm::operator=(const AForm &src)
{
	if (this != &src)
		_signed = src._signed;
	printMsg("AForm copy assignment operator called\n");
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const AForm &src)
{
	stream << "AForm " << src.getName();
	if (src.getSigned() == false)
		stream << " is not signed yet. ";
	else
		stream << " is signed. ";
	stream << "Grade required to sign is " << src.getGradeToSign() << ". ";
	stream << "Grade required to execute is " << src.getGradeToExecute() << ".\n";
	return (stream);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

void	AForm::execute(Bureaucrat const & executor)
{
	if (_signed == false)
		return ;
	if (executor.getGrade() < _gradeToExecute)
		throw AForm::GradeTooLowException();
	action();
}

const std::string	&AForm::getName() const
{
	return (_name);
}

const std::string	&AForm::getTarget() const
{
	return (_target);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	printMsg(std::string str)
{
	if (DEBUG == 1)
		std::cout << str;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("form not signed");
}
