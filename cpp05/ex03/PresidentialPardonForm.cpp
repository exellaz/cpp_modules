/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:57:27 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/07 14:52:24 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", "default_target", 25, 5)
{
	debugPrint("Default Presidential constructor called\n");
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", target, 25, 5)
{
	debugPrint("Presidential constructor called\n");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src)
{
	debugPrint("Presidential copy constructor called\n");
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	AForm::operator=(src);
	debugPrint("Presidential copy assignment operator called\n");
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	debugPrint("Presidential destructor called\n");
}

void	PresidentialPardonForm::action() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}

