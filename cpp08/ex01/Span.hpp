/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:57:53 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/24 14:15:35 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <iostream>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& src);
		~Span();

		void	addNumber(int number);
		Span&	operator=(const Span& src);

		int					longestSpan();
		int					shortestSpan();
		std::vector<int>&	getNumbers();
		unsigned int		getMaxSize() const;

	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;
};

#endif
