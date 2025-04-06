/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:44:17 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/06 13:53:14 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		AForm();
		AForm(const std::string &name, const std::string &target, \
			const int gradeToSign, const int gradeToExecute);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual	~AForm();

		void			beSigned(const Bureaucrat &bureaucrat);
		void			execute(Bureaucrat const & executor) const;
		virtual void	action() const = 0;

		const std::string	&getName() const;
		const std::string	&getTarget() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

	private:
		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &stream, const AForm &src);
void			debugPrint(std::string str);

#endif
