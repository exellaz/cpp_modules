/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:01:36 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/16 21:17:03 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& src);
		Array&	operator=(const Array& src);
		T&		operator[](unsigned int i);
		~Array();

		unsigned int	size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		T*				_array;
		unsigned int	_size;
};

# include "Array.tpp"

#endif