/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:17:13 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/23 15:20:35 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	get_level_index(std::string	level)
{
	std::string	levels_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels_arr[i])
			return (i);
	}
	return (-1);
}

int	main(int ac, char *av[])
{
	Harl	harlFilter;

	if (ac != 2)
		return (1);
	harlFilter.complain(av[1]);
	return (0);
}
