/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:23:02 by kkhai-ki          #+#    #+#             */
/*   Updated: 2025/04/14 16:32:05 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data		date = {29, "August", 2025};
	uintptr_t	raw = Serializer::serialize(&date);
	Data*		newDate = Serializer::deserialize(raw);

	std::cout << "It is currently " << newDate->day << " of " \
		<< newDate->month << " " << newDate->year << ".\n";
	return 0;
}
