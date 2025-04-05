/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:29:53 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/05 16:41:21 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "default_target", 72, 45)
{
	printMsg("Default Robotomy constructor called\n");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", target, 72, 45)
{
	printMsg("Robotomy constructor called\n");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src)
{
	printMsg("Robotomy copy constructor called\n");
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	AForm::operator=(src);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	printMsg("Robotomy destructor called\n");
}

void	RobotomyRequestForm::action() const
{

}