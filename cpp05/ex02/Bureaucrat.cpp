/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:42:17 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/06 13:56:10 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
	: _name("John Doe"),
	_grade(150)
{
	if (DEBUG == 1)
		std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	if (DEBUG == 1)
	{
		std::cout << "Bureaucrat " << this->_name \
			<< " has been destroyed" << std::endl;
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		this->_grade = grade;
		if (DEBUG == 1)
		{
			std::cout << "Bureaucrat " << this->_name \
				<< " has been constructed with grade " << grade << std::endl;
		}
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: _name(src._name),
	_grade(src._grade)
{
	if (DEBUG == 1)
		std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->_grade = src._grade;
	if (DEBUG == 1)
		std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &src)
{
	stream << src.getName() << ", bureaucrat grade ";
	stream << src.getGrade() << ".";
	return (stream);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		this->_grade--;
		std::cout << this->_name << "'s new grade is " << this->_grade << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		this->_grade++;
		std::cout << this->_name << "'s new grade is " << this->_grade << std::endl;
	}
}

void	Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned() == true)
	{
		std::cout << _name << " couldn't sign " << form.getName() \
			<< " because it is already signed.\n";
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << ".\n";
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() \
			<< " because " << e.what() << "\n";
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName() \
			<< " because " << e.what() << "\n";
	}
}

const std::string	&Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
