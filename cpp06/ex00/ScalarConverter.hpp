/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:43:18 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/11 18:09:56 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cstdio>
# include <cstring>
# include <limits>
# include <cerrno>
# include <cmath>
# include <sstream>
# include <iomanip>

# define INT_MIN std::numeric_limits<int>::min() //-2147483648
# define INT_MAX std::numeric_limits<int>::max() //2147483647
# define NEG_FLOAT_MAX -std::numeric_limits<float>::max() //-3.40282e+38
# define FLOAT_MIN std::numeric_limits<float>::min() //1.17549e-38
# define FLOAT_MAX std::numeric_limits<float>::max() //3.40282e+38
# define NEG_DOUBLE_MAX -std::numeric_limits<double>::max()//-1.79769e+308
# define DOUBLE_MIN std::numeric_limits<double>::min() //2.22507e-308
# define DOUBLE_MAX std::numeric_limits<double>::max() //1.79769e+308

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
};

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter& src);
		ScalarConverter&	operator=(ScalarConverter& src);
		~ScalarConverter();

		static void	convert(const std::string& input);

	private:
};

e_type	checkTypes(const std::string& input);
void	convertChar(const std::string& input);
void	convertInt(const std::string& input);
void	convertFloat(const std::string& input);
void	convertDouble(const std::string& input);
#endif
