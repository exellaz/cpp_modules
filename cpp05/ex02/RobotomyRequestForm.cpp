/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:29:53 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/07 14:04:14 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "default_target", 72, 45)
{
	debugPrint("Default Robotomy constructor called\n");
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", target, 72, 45)
{
	debugPrint("Robotomy constructor called\n");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src)
{
	debugPrint("Robotomy copy constructor called\n");
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	AForm::operator=(src);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	debugPrint("Robotomy destructor called\n");
}

void	RobotomyRequestForm::action() const
{
	static bool	seeded = false;

	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}
	std::cout << "* drilling noises *\n";
	if (rand() % 2 == 0)
		std::cout << getTarget() << " has been robotomized successfully.\n";
	else
		std::cout << "Robotomy of " << getTarget() << " failed.\n";
}
