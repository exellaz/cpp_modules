/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:49:24 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/18 23:26:17 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
typename T::iterator	easyfind(T& container, int needle)
{
	typename T::iterator	ptr;

	ptr = std::find(container.begin(), container.end(), needle);

	if (ptr == container.end())
		throw std::exception();

	return ptr;
}

template<typename T>
void	test_easyfind(T& container, int needle, std::string name)
{
	typename T::iterator	it;

	std::cout << YELLOW << "[Test] " << name << "\n" << RESET;
	try {
		it = easyfind(container, needle);
		std::cout << "Found number: " << *it << " at index "
			<< std::distance(container.begin(), it) << ".\n";
	}
	catch (std::exception &e) {
		std::cout << "Could not find number\n";
	}
}

template<typename T>
void	printContainer(T& container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it;
		if (it != container.end())
	}
}