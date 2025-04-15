/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:14:58 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/15 10:31:46 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	printElement(const T& element)
{
	std::cout << element << "\n";
}

int	main()
{
	int			iArr[] = {1, 2, 3, 4, 5};
	char		charArr[] = {'H','e','l','l','o','\0'};
	std::string	strArr[] = {"Hello", "There"};

	iter(iArr, 5, printElement);
	iter(charArr, 5, printElement);
	iter(strArr, 2, printElement);

	return 0;
}
