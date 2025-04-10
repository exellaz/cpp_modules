/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:43:18 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/10 17:33:38 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <cerrno>
# include <cmath>

# define INT_MIN std::numeric_limits<int>::min() //-2147483648
# define INT_MAX std::numeric_limits<int>::max() //2147483647
# define NEG_FLOAT_MAX -std::numeric_limits<float>::max() //-3.40282e+38
# define FLOAT_MIN std::numeric_limits<float>::min() //1.17549e-38
# define FLOAT_MAX std::numeric_limits<float>::max() //3.40282e+38
# define NEG_DOUBLE_MAX -std::numeric_limits<double>::max()//-1.79769e+308
# define DOUBLE_MIN std::numeric_limits<double>::min() //2.22507e-308
# define DOUBLE_MAX std::numeric_limits<double>::max() //1.79769e+308

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter& src);
		ScalarConverter&	operator=(ScalarConverter& src);
		~ScalarConverter();

		static void	convert(const std::string& input);

	private:
		static bool	checkTypes(const std::string& input);
};

#endif
