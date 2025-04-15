/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:04:40 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/15 10:31:10 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T* array, size_t length, void(*f)(T&))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void	iter(T* array, size_t length, void(*f)(const T&))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif
