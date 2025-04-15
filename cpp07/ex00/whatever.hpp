/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:22:46 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/15 08:47:59 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T& a, T& b)
{
	T	temp = a;
	a = b;
	b = temp;
}

template<typename T>
const T&	min(const T& a, const T& b)
{
	return ((a < b) ? a : b);
}

template<typename T>
const T&	max(const T& a, const T& b)
{
	return ((a > b) ? a : b);
}

#endif
