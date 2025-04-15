/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:16:49 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/15 15:59:41 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array()
	: _array(NULL),
	_size(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n)
	: _array(new T[n]),
	_size(n)
{
}

template<typename T>
Array<T>::Array(const Array& src)
	: _array(new T[src._size]),
	_size(src._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array& src)
{
	if (this != src) {
		delete [] _array;
		_size = src._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src._array[i];
	}
	return *this;
}

template<typename T>
T&	Array<T>::operator[](unsigned int i)
{
	// if (i >= _size)
	return _array[i];
}

template<typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}


