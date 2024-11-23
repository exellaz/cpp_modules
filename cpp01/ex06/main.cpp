/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:17:13 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/23 15:36:01 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char *av[])
{
	Harl	harlFilter;

	if (ac != 2)
		return (1);
	harlFilter.complain(av[1]);
	return (0);
}
