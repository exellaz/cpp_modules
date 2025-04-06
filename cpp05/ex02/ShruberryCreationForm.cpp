/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:18:51 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/06 14:35:29 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm()
	: AForm("ShruberryCreationForm","default_target", 145, 137)
{
	debugPrint("Default Shruberry constructor called\n");
}

ShruberryCreationForm::ShruberryCreationForm(const std::string &target)
	: AForm("ShruberryCreationForm", target, 145, 137)
{
	debugPrint("Shruberry constructor called\n");
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &src)
	: AForm(src)
{
	debugPrint("Shruberry copy constructor called\n");
}

ShruberryCreationForm	&ShruberryCreationForm::operator=(const ShruberryCreationForm &src)
{
	AForm::operator=(src);
	return *this;
}

ShruberryCreationForm::~ShruberryCreationForm()
{
	debugPrint("Shruberry destructor called\n");
}

void	ShruberryCreationForm::action() const
{
	std::ofstream	file((getTarget() + "_shruberry").c_str());

	file << "     ccee88oo\n"
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
}
