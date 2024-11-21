/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:11:38 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/21 13:02:49 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

static bool	validate_args(int ac, char *av[]);
static std::string	replace_str(std::string initial, std::string toReplace, std::string replaceWith);
static void	read_and_replace(char *av[]);

int	main(int ac, char *av[])
{
	if (!validate_args(ac, av))
		return (1);
	read_and_replace(av);
	return (0);
}

static std::string	replace_str(std::string initial, std::string toReplace, std::string replaceWith)
{
	size_t		i = 0;
	size_t		found;
	std::string	result;

	if (toReplace.empty() == true)
		return (initial);
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

static bool	validate_args(int ac, char *av[])
{
	std::ifstream	file_read;

	if (ac != 4)
	{
		std::cout << "Error: expected: ./fake_sed <filename> <toReplace> <replaceWith>" << std::endl;
		return (false);
	}
	file_read.open(av[1]);
	if (file_read.is_open() == false)
	{
		std::cout << "Error: Invalid file" << std::endl;
		return (false);
	}
	file_read.close();
	return (true);
}

static void	read_and_replace(char *av[])
{
	const std::string	&filename(av[1]);
	std::ifstream		read_file;
	std::ofstream		write_file;
	std::ostringstream	buffer;

	read_file.open(filename.c_str());
	write_file.open((filename + ".replace").c_str());
	buffer << read_file.rdbuf();
	write_file << replace_str(buffer.str(), av[2], av[3]);
}
