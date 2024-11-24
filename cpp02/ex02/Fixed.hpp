/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:46:35 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/24 15:46:31 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		static const int	_bits = 8;
		int					_raw_bits;

	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed(void);
		Fixed	&operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toInt(void) const;
		float	toFloat(void) const;
		bool	operator>(const Fixed &f) const;
		bool	operator<(const Fixed &f) const;
		bool	operator>=(const Fixed &f) const;
		bool	operator<=(const Fixed &f) const;
		bool	operator==(const Fixed &f) const;
		bool	operator!=(const Fixed &f) const;
		Fixed	operator+(const Fixed &f) const;
		Fixed	operator-(const Fixed &f) const;
		Fixed	operator*(const Fixed &f) const;
		Fixed	operator/(const Fixed &f) const;
};

std::ostream	&operator<<(std::ostream &stream, const Fixed &f);

#endif
