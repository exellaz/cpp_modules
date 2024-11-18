/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:41:27 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/18 16:57:20 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Str address: " << &str << std::endl;
	std::cout << "stringPTR address: " << &stringPTR << std::endl;
	std::cout << "stringREF address: " << &stringREF << std::endl << std::endl;
	std::cout << "Str value: " << str << std::endl;
	std::cout << "stringPTR value: " << stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;
}
