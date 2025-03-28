/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:44:17 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/03/27 22:52:51 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		~Form();
		Form(const std::string &name, const int gradeToSign, \
				const int gradeToExecute);
		Form(const Form &src);
		Form &operator=(const Form &src);

		void	beSigned(const Bureaucrat &bureaucrat);

		const std::string	&getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

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

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &stream, const Form &src);
void			printMsg(std::string str);

#endif
