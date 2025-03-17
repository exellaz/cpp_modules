/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:41:54 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/03/17 11:37:11 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Constructing a Bureaucrat with grade 50" << std::endl;
	Bureaucrat	A("Cain", 50);

	try
	{
		std::cout << "Constructing a Bureaucrat with grade -1" << std::endl;
		Bureaucrat	B("David", -1);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Constructing a Bureaucrat with grade 151" << std::endl;
		Bureaucrat	C("Johnny", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
