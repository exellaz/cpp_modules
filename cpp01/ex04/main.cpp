/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:11:38 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/21 11:42:56 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <iostream>

std::string	replace_str(std::string initial, std::string toReplace, std::string replaceWith)
{
	size_t		i = 0;
	size_t		found;
	std::string	result;

	found = initial.find(toReplace);
	while (found != std::string::npos)
	{
		result.append(initial.substr(i, found - i));
		result.append(replaceWith);
		i = found + toReplace.length();
		found = initial.find(toReplace, i);
	}
	result.append(initial.substr(i, initial.length()));
	return (result);
}

int	main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "Error: expected: ./fake_sed <filename> <toReplace> <replaceWith>" << std::endl;
		return (1);
	}
	std::string		filename = av[1];
	std::string		toReplace = av[2];
	std::string		replaceWith = av[3];
	std::string		content;
	std::string		line;
	std::ifstream	file_read(filename.c_str());
	if (file_read.is_open() == false)
	{
		std::cout << "Error: Invalid file" << std::endl;
		return (1);
	}
	std::ofstream file_output(filename.append(".replace").c_str());
	while (std::getline(file_read, line))
		content.append(line).append("\n");
	content = replace_str(content, toReplace, replaceWith);
	file_output << content;
	return (0);
}
