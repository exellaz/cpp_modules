/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:43:18 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/08 16:00:22 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter& src);
		ScalarConverter&	operator=(ScalarConverter& src);
		~ScalarConverter();

		static void	convert(const std::string& input);
};

#endif
