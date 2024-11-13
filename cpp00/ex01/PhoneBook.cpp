/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:43:56 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/11/13 20:02:35 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

std::string	PhoneBook::_truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0,9) + ".");
	else
		return(str);
}

std::string	PhoneBook::trim_whitespace(std::string str)
{
	std::string	whitespace	= " \t\n\r\v\f";
	size_t		start;
	size_t		end;

	start = str.find_first_not_of(whitespace);
	end = str.find_last_not_of(whitespace);
	if (start == std::string::npos || end == std::string::npos)
		return ("");
	if (start == end)
		return (str);
	return (str.substr(start, end - start + 1));
}

void	PhoneBook::get_input(std::string prompt, std::string &str)
{
	std::cout << prompt << std::endl;
	std::getline(std::cin, str);
	str = trim_whitespace(str);
}

void	PhoneBook::add_contact(void)
{
	std::string	input;

	while (_contact_array[this->_index].get_first_name() == "")
	{
		get_input("Enter your first name:", input);
		_contact_array[this->_index].set_first_name(input);
	}
	while (_contact_array[this->_index].get_last_name() == "")
	{
		get_input("Enter your last name:", input);
		_contact_array[this->_index].set_last_name(input);
	}
	while (_contact_array[this->_index].get_nickname() == "")
	{
		get_input("Enter your nickname:", input);
		_contact_array[this->_index].set_nickname(input);
	}
	while (_contact_array[this->_index].get_phone_number() == "")
	{
		get_input("Enter your phone number:", input);
		_contact_array[this->_index].set_phone_number(input);
	}
	while (_contact_array[this->_index].get_secret() == "")
	{
		get_input("Enter your darkest secret:", input);
		_contact_array[this->_index].set_secret(input);
	}
	if (this->_index == 7)
		this->_index = 0;
	else
		this->_index++;
	std::cout << "Contact added Successfully" << std::endl;
	std::cout << "Press Enter to continue..." << std::endl;
	while (std::cin.get() != '\n')
		;
}

void	PhoneBook::display_contact_table(void)
{
	std::cout	<< "+----------+----------+----------+----------+" << std::endl
				<< "|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_contact_array[i].get_first_name() == "")
			break ;
		else
		{
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << i;
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << this->_truncate(this->_contact_array[i].get_first_name());
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << this->_truncate(this->_contact_array[i].get_last_name());
			std::cout << std::setw(1) << "|";
			std::cout << std::setw(10) << this->_truncate(this->_contact_array[i].get_nickname());
			std::cout << std::setw(1) << "|" << std::endl;
			std::cout << "+----------+----------+----------+----------+" << std::endl;
		}
	}
	// while (std::cin.get() != '\n')
	// 	;
}

void	PhoneBook::search_contact(void)
{
	std::string	input;
	size_t		index;

	get_input("Index of contact to display:", input);
	index = input[0] - '0';
	system("clear");
	if (input.length() != 1 || !std::isdigit(input[0]))
	{
		std::cout << "Invalid index! Please enter a digit from 0 to 7." << std::endl;
	}
	else if (this->_contact_array[index].get_first_name() == "")
	{
		std::cout << "No record at index [" << index << "]. ADD a contact and try again." << std::endl;
	}
	else
	{
		std::cout << "CONTACT[" << index << "]" << std::endl;
		std::cout << "FIRST NAME: " << this->_contact_array[index].get_first_name() << std::endl;
		std::cout << "LAST NAME: " << this->_contact_array[index].get_last_name() << std::endl;
		std::cout << "NICKNAME: " << this->_contact_array[index].get_nickname() << std::endl;
		std::cout << "PHONE NUMBER: " << this->_contact_array[index].get_phone_number() << std::endl;
		std::cout << "DARKEST SECRET: " << this->_contact_array[index].get_secret() << std::endl;
	}
	std::cout << "Press Enter to continue..." << std::endl;
	while (std::cin.get() != '\n')
		;
}
