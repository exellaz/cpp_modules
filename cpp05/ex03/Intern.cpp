/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:38:09 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/08 08:03:22 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	debugPrint("Intern default constructor called\n");
}

Intern::Intern(const Intern &src)
{
	(void)src;
	debugPrint("Intern copy constructor called\n");
}

Intern	&Intern::operator=(const Intern &src)
{
	(void)src;
	debugPrint("Intern copy assignment operator called\n");
	return (*this);
}

Intern::~Intern()
{
	debugPrint("Intern destructor called\n");
}

AForm	*Intern::createShrubbery(const std::string &target)
{
	return (new ShruberryCreationForm(target));
}

AForm	*Intern::createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	static const FormEntry	formTable[] = {
		{"ShruberryCreationForm", createShrubbery},
		{"RobotomyRequestForm", createRobotomy},
		{"PresidentialPardonForm", createPresidential}
	};
	static const int	formTypes = sizeof(formTable) / sizeof(FormEntry);

	for (int i = 0; i < formTypes; i++)
	{
		if (formName == formTable[i].name)
		{
			std::cout << "Intern creates " << formName << "\n";
			return (formTable[i].formCreator(target));
		}
	}
	std::cout << "Cannot find form of " << formName << "\n";
	return (NULL);
}

