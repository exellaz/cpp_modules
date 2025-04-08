/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:38:13 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/08 07:52:10 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShruberryCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

struct FormEntry
{
	const char	*name;
	AForm		*(*formCreator)(const std::string &target);
};

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();

		AForm	*makeForm(const std::string &formName, const std::string &target);

	private:
		static AForm	*createShrubbery(const std::string &target);
		static AForm	*createRobotomy(const std::string &target);
		static AForm	*createPresidential(const std::string &target);
};

#endif
